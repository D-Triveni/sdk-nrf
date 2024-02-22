/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/** @file
 * @brief WPA SUPP events
 */

#include <stdio.h>
#include <zephyr/net/net_event.h>
#include <ctrl_iface_zephyr.h>
#include <supp_events.h>
#include <utils.h>
#include <supp_main.h>

#define WPA_SUPP_EVENTS (NET_EVENT_WPA_SUPP_READY | \
			 NET_EVENT_WPA_SUPP_NOT_READY | \
			 NET_EVENT_WPA_SUPP_IFACE_ADDED | \
			 NET_EVENT_WPA_SUPP_CMD_IFACE_REMOVING | \
			 NET_EVENT_WPA_SUPP_CMD_IFACE_REMOVED)

static struct net_mgmt_event_callback net_wpa_supp_cb;
struct wpa_supplicant *wpa_s = NULL;

K_SEM_DEFINE(wpa_supp_ready_sem, 0, 1);

static void handle_wpa_supp_ready(struct net_mgmt_event_callback *cb)
{
	int retry_count = 0;
retry:
	wpa_s = z_wpas_get_handle_by_ifname("wlan0");
	if (!wpa_s && retry_count++ < 5) {
		printf("%s: Unable to get wpa_s handle for %s\n",
			      __func__, "wlan0");
		goto retry;
	}

	if (!wpa_s) {
		printf("%s: Unable to get wpa_s handle for %s\n",
				__func__, "wlan0");
	}

	k_sem_give(&wpa_supp_ready_sem);

}

static void wpa_supp_event_handler(struct net_mgmt_event_callback *cb,
                                    uint32_t mgmt_event, struct net_if *iface)
{
        switch (mgmt_event) {
        case NET_EVENT_WPA_SUPP_READY:
		printf("Supplicant is ready");
		handle_wpa_supp_ready(cb);
                break;
	case NET_EVENT_WPA_SUPP_NOT_READY:
		printf("Supplicant is not ready");
                break;
	case  NET_EVENT_WPA_SUPP_IFACE_ADDED:
		printf("Interface added");
                break;
	case NET_EVENT_WPA_SUPP_CMD_IFACE_REMOVING:
		printf("Interface is removing");
                break;
	case NET_EVENT_WPA_SUPP_CMD_IFACE_REMOVED:
		printf("Interface removed");
                break;
        default:
                break;
        }
}

int wpa_supp_events_init(void)
{
	net_mgmt_init_event_callback(&net_wpa_supp_cb,
                                     wpa_supp_event_handler,
                                     WPA_SUPP_EVENTS);
        net_mgmt_add_event_callback(&net_wpa_supp_cb);

	k_sem_take(&wpa_supp_ready_sem, K_FOREVER);

	/* Check for ctrl_iface initialization */
	if (wpa_s->ctrl_iface->sock_pair[0] < 0) {
		return -1;
	}

	return 0;
}
