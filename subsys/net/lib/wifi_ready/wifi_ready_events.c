/*
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/net/net_event.h>
#include <ctrl_iface_zephyr.h>
#include <supp_events.h>
#include <supp_main.h>
#include <zephyr/logging/log.h>
#include <zephyr/kernel.h>
#include <net/library.h>
LOG_MODULE_REGISTER(wifi_ready_events_handling, CONFIG_WIFI_READY_EVENT_HANDLING_LOG_LEVEL);

static app_callbacks_t callbacks;
struct net_mgmt_event_callback net_wpa_supp_cb;

static void handle_wpa_supp_ready(struct net_mgmt_event_callback *cb)
{
	LOG_INF("In supp ready event handler");

	callbacks.start_app();		
}

static void handle_wpa_supp_stop(struct net_mgmt_event_callback *cb)
{
	LOG_INF("In supp not ready event handler");
	callbacks.stop_app();		
}

static void wpa_supp_event_handler(struct net_mgmt_event_callback *cb,
	uint32_t mgmt_event, struct net_if *iface)
{
	/* TODO: Handle other events */
	switch (mgmt_event) {
	case NET_EVENT_WPA_SUPP_READY:
		LOG_INF("Invoking supp ready event handler");
		handle_wpa_supp_ready(cb);
		break;
	case NET_EVENT_WPA_SUPP_NOT_READY:
		LOG_INF("Invoking supp ready event handler");
		handle_wpa_supp_stop(cb);
		break;
	default:
		LOG_DBG("Unhandled event (%d)", mgmt_event);
		break;
	}
}

int register_events(app_callbacks_t cb)
{
	callbacks = cb;

	LOG_INF("Registering supp events");
	net_mgmt_init_event_callback(&net_wpa_supp_cb, wpa_supp_event_handler, WPA_SUPP_EVENTS);
	net_mgmt_add_event_callback(&net_wpa_supp_cb);

	return 0;
}
