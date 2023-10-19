/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/** @file
 * @brief Wi-Fi Raw Tx Packet sample
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(raw_tx_packet, CONFIG_LOG_DEFAULT_LEVEL);

#include <nrfx_clock.h>
#include <zephyr/kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <zephyr/shell/shell.h>
#include <zephyr/sys/printk.h>
#include <zephyr/init.h>

#include <zephyr/net/net_if.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_event.h>
#include <zephyr/net/socket.h>
#include <zephyr/drivers/gpio.h>

#include "net_private.h"

#define WIFI_SHELL_MODULE "wifi"

#define WIFI_SHELL_MGMT_EVENTS (NET_EVENT_WIFI_CONNECT_RESULT |		\
				NET_EVENT_WIFI_DISCONNECT_RESULT)

#define MAX_SSID_LEN        32
#define DHCP_TIMEOUT        70
#define CONNECTION_TIMEOUT  100
#define STATUS_POLLING_MS   300

static struct net_mgmt_event_callback wifi_shell_mgmt_cb;
static struct net_mgmt_event_callback net_shell_mgmt_cb;

static struct {
	const struct shell *sh;
	union {
		struct {
			uint8_t connected	: 1;
			uint8_t connect_result	: 1;
			uint8_t disconnect_requested	: 1;
			uint8_t _unused		: 5;
		};
		uint8_t all;
	};
} context;

struct nrf_wifi_fmac_rawpkt_info {
        /** Magic number to distinguish packet is raw packet */
        unsigned int magic_number;
        /** Data rate of the packet */
        unsigned char data_rate;
        /** Packet length */
        unsigned short packet_length;
        /** Mode describing if packet is VHT, HT, HE or Legacy */
        unsigned char tx_mode;
        /** Wi-Fi access category mapping for packet */
        unsigned char queue;
        /** reserved parameter for driver */
        unsigned char reserved;
};

/* SSID: NRF_RAW_TX_PACKET_APP
 * Transmitter Address: a0:69:60:e3:52:15
 * */
char beacon_frame[] = {
0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0x69, 0x60, 0xe3, 0x52, 0x15,
0xa0, 0x59, 0x50, 0xe3, 0x52, 0x15, 0xb0, 0x53,

0xf0, 0xcf, 0x29, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00, 0x11, 0x04, 0x00, 0x15, 0x4E, 0x52,
0x46, 0x5F, 0x52, 0x41, 0x57, 0x5F, 0x54, 0x58, 0x5F, 0x50, 0x41, 0x43, 0x4B, 0x45, 0x54, 0x5F,
0x41, 0x50, 0x50, 0x54, 0x72, 0x61, 0x63, 0x6b, 0x5f, 0x31, 0x36, 0x38, 0x36, 0x31, 0x32, 0x32,
0x38, 0x36, 0x35, 0x01, 0x08, 0x82, 0x84, 0x8b, 0x96, 0x0c, 0x12, 0x18, 0x24, 0x03, 0x01, 0x06,
0x05, 0x04, 0x00, 0x02, 0x00, 0x00, 0x2a, 0x01, 0x04, 0x32, 0x04, 0x30, 0x48, 0x60, 0x6c, 0x30,
0x14, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x04, 0x01, 0x00, 0x00, 0x0f, 0xac, 0x04, 0x01, 0x00, 0x00,
0x0f, 0xac, 0x02, 0xcc, 0x00, 0x3b, 0x02, 0x51, 0x00, 0x2d, 0x1a, 0x0c, 0x00, 0x17, 0xff, 0xff,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2c, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x3d, 0x16, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x08, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00,
0x00, 0x40, 0xff, 0x1a, 0x23, 0x01, 0x78, 0x10, 0x1a, 0x00, 0x00, 0x00, 0x20, 0x0e, 0x09, 0x00,
0x09, 0x80, 0x04, 0x01, 0xc4, 0x00, 0xfa, 0xff, 0xfa, 0xff, 0x61, 0x1c, 0xc7, 0x71, 0xff, 0x07,
0x24, 0xf0, 0x3f, 0x00, 0x81, 0xfc, 0xff, 0xdd, 0x18, 0x00, 0x50, 0xf2, 0x02, 0x01, 0x01, 0x01,
0x00, 0x03, 0xa4, 0x00, 0x00, 0x27, 0xa4, 0x00, 0x00, 0x42, 0x43, 0x5e, 0x00, 0x62, 0x32, 0x2f, 0x00
};

static int cmd_wifi_status(void)
{
	struct net_if *iface = net_if_get_default();
	struct wifi_iface_status status = { 0 };
	int ret;

	ret = net_mgmt(NET_REQUEST_WIFI_IFACE_STATUS, iface, &status,
				sizeof(struct wifi_iface_status));
	if (ret) {
		LOG_INF("Status request failed: %d\n", ret);
		return ret;
	}

	LOG_INF("==================");
	LOG_INF("State: %s", wifi_state_txt(status.state));

	if (status.state >= WIFI_STATE_ASSOCIATED) {
		uint8_t mac_string_buf[sizeof("xx:xx:xx:xx:xx:xx")];

		LOG_INF("Interface Mode: %s",
		       wifi_mode_txt(status.iface_mode));
		LOG_INF("Link Mode: %s",
		       wifi_link_mode_txt(status.link_mode));
		LOG_INF("SSID: %-32s", status.ssid);
		LOG_INF("BSSID: %s",
		       net_sprint_ll_addr_buf(
				status.bssid, WIFI_MAC_ADDR_LEN,
				mac_string_buf, sizeof(mac_string_buf)));
		LOG_INF("Band: %s", wifi_band_txt(status.band));
		LOG_INF("Channel: %d", status.channel);
		LOG_INF("Security: %s", wifi_security_txt(status.security));
		LOG_INF("MFP: %s", wifi_mfp_txt(status.mfp));
		LOG_INF("RSSI: %d", status.rssi);
		LOG_INF("TWT: %s", status.twt_capable ? "Supported" : "Not supported");
	}
	return 0;
}

static void handle_wifi_connect_result(struct net_mgmt_event_callback *cb)
{
	const struct wifi_status *status =
		(const struct wifi_status *) cb->info;

	if (context.connected) {
		return;
	}

	if (status->status) {
		LOG_ERR("Connection failed (%d)", status->status);
	} else {
		LOG_INF("Connected");
		context.connected = true;
	}

	context.connect_result = true;
}

static void handle_wifi_disconnect_result(struct net_mgmt_event_callback *cb)
{
	const struct wifi_status *status =
		(const struct wifi_status *) cb->info;

	if (!context.connected) {
		return;
	}

	if (context.disconnect_requested) {
		LOG_INF("Disconnection request %s (%d)",
			 status->status ? "failed" : "done",
					status->status);
		context.disconnect_requested = false;
	} else {
		LOG_INF("Received Disconnected");
		context.connected = false;
	}

	cmd_wifi_status();
}

static void wifi_mgmt_event_handler(struct net_mgmt_event_callback *cb,
				     uint32_t mgmt_event, struct net_if *iface)
{
	switch (mgmt_event) {
	case NET_EVENT_WIFI_CONNECT_RESULT:
		handle_wifi_connect_result(cb);
		break;
	case NET_EVENT_WIFI_DISCONNECT_RESULT:
		handle_wifi_disconnect_result(cb);
		break;
	default:
		break;
	}
}

static void print_dhcp_ip(struct net_mgmt_event_callback *cb)
{
	/* Get DHCP info from struct net_if_dhcpv4 and print */
	const struct net_if_dhcpv4 *dhcpv4 = cb->info;
	const struct in_addr *addr = &dhcpv4->requested_ip;
	char dhcp_info[128];

	net_addr_ntop(AF_INET, addr, dhcp_info, sizeof(dhcp_info));

	LOG_INF("DHCP IP address: %s", dhcp_info);
}

static void net_mgmt_event_handler(struct net_mgmt_event_callback *cb,
				    uint32_t mgmt_event, struct net_if *iface)
{
	switch (mgmt_event) {
	case NET_EVENT_IPV4_DHCP_BOUND:
		print_dhcp_ip(cb);
		break;
	default:
		break;
	}
}

#ifdef CONFIG_RAW_TX_PACKET_SAMPLE_CONNECTION_MODE
static int __wifi_args_to_params(struct wifi_connect_req_params *params)
{
	params->timeout = SYS_FOREVER_MS;

	/* SSID */
	params->ssid = CONFIG_RAW_TX_PACKET_SAMPLE_SSID;
	params->ssid_length = strlen(params->ssid);

#if defined(CONFIG_RAW_TX_PACKET_SAMPLE_KEY_MGMT_WPA2)
	params->security = 1;
#elif defined(CONFIG_RAW_TX_PACKET_SAMPLE_KEY_MGMT_WPA2_256)
	params->security = 2;
#elif defined(CONFIG_RAW_TX_PACKET_SAMPLE_KEY_MGMT_WPA3)
	params->security = 3;
#else
	params->security = 0;
#endif

#if !defined(CONFIG_RAW_TX_PACKET_SAMPLE_KEY_MGMT_NONE)
	params->psk = CONFIG_RAW_TX_PACKET_SAMPLE_PASSWORD;
	params->psk_length = strlen(params->psk);
#endif
	params->channel = WIFI_CHANNEL_ANY;

	/* MFP (optional) */
	params->mfp = WIFI_MFP_OPTIONAL;

	return 0;
}

static int wifi_connect(void)
{
	struct net_if *iface = net_if_get_default();
	static struct wifi_connect_req_params cnx_params;

	context.connected = false;
	context.connect_result = false;
	__wifi_args_to_params(&cnx_params);

	if (net_mgmt(NET_REQUEST_WIFI_CONNECT, iface,
		     &cnx_params, sizeof(struct wifi_connect_req_params))) {
		LOG_ERR("Connection request failed");

		return -ENOEXEC;
	}

	LOG_INF("Connection requested");

	return 0;
}
#endif

#ifdef CONFIG_RAW_TX_PACKET_SAMPLE_IDLE_MODE
static void wifi_set_channel(void)
{
	struct net_if *iface;
	struct wifi_channel_info channel_info = {0};
	int ret;

	channel_info.oper = WIFI_MGMT_SET;

	if (channel_info.if_index == 0) {
		iface = net_if_get_first_wifi();
		if (iface == NULL) {
			LOG_ERR("Cannot find the default wifi interface");
			return;
		}
		channel_info.if_index = net_if_get_by_iface(iface);
	} else {
		iface = net_if_get_by_index(channel_info.if_index);
		if (iface == NULL) {
			LOG_ERR("Cannot find interface for if_index %d",
					      channel_info.if_index);
			return;
		}
	}

	if (channel_info.oper == WIFI_MGMT_SET) {
		channel_info.channel = CONFIG_RAW_TX_PACKET_SAMPLE_CHANNEL;
		if ((channel_info.channel < WIFI_CHANNEL_MIN) ||
			   (channel_info.channel > WIFI_CHANNEL_MAX)) {
				LOG_ERR("Invalid channel number. Range is (1-233)");
				return;
		}
	}

	ret = net_mgmt(NET_REQUEST_WIFI_CHANNEL, iface,
			&channel_info, sizeof(channel_info));

	if (ret) {
		LOG_ERR(" Channel setting failed %d\n", ret);
			return;
	}

	LOG_INF("Wi-Fi channel set to %d", channel_info.channel);
}
#endif

static void wifi_set_mode(void)
{
	int ret;
	struct net_if *iface;
	struct wifi_mode_info mode_info = {0};

	mode_info.oper = WIFI_MGMT_SET;

	if (mode_info.if_index == 0) {
		iface = net_if_get_default();
		if (iface == NULL) {
			LOG_ERR("Cannot find the default wifi interface");
			return;
		}
		mode_info.if_index = net_if_get_by_iface(iface);
	} else {
		iface = net_if_get_by_index(mode_info.if_index);
		if (iface == NULL) {
			LOG_ERR("Cannot find interface for if_index %d",
				      mode_info.if_index);
			return;
		}
	}

	mode_info.mode =  WIFI_STA_MODE | WIFI_TX_INJECTION_MODE ;

	ret = net_mgmt(NET_REQUEST_WIFI_MODE, iface, &mode_info, sizeof(mode_info));
	if (ret) {
		LOG_ERR("Mode setting failed %d", ret);
	}
}

static void wifi_send_raw_tx_packet(void)
{
	struct sockaddr_ll sa;
	int sockfd, ret;
	struct net_if *iface;
	struct nrf_wifi_fmac_rawpkt_info raw_tx_pkt;
	char *buffer = NULL;
	int buf_length;

	/* Create a raw socket */
	sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW);
	if (sockfd < 0) {
		LOG_ERR("Unable to create a socket");
		return;
	}

	iface = net_if_get_default();
	if(!iface) {
		LOG_ERR("Unable to get default interface");
		return;
	}

	sa.sll_family = AF_PACKET;
	sa.sll_ifindex = net_if_get_by_iface(iface);

	/* Bind the socket */
	ret = bind(sockfd, (struct sockaddr *)&sa, sizeof(struct sockaddr_ll));
	if (ret < 0) {
		LOG_ERR("Error: Unable to bind socket to the network interface:%d", errno);
		close(sockfd);
		return;
	}

	/* Raw Tx Packet header */
	raw_tx_pkt.magic_number = 0x12345678;
	raw_tx_pkt.data_rate = CONFIG_RAW_TX_PACKET_SAMPLE_RATE_VALUE;
	raw_tx_pkt.packet_length = sizeof(beacon_frame);
	raw_tx_pkt.tx_mode = CONFIG_RAW_TX_PACKET_SAMPLE_RATE_FLAGS;
	raw_tx_pkt.queue = CONFIG_RAW_TX_PACKET_SAMPLE_QUEUE_NUM;
	raw_tx_pkt.reserved = 0;

	buffer = malloc(sizeof(struct nrf_wifi_fmac_rawpkt_info) + sizeof(beacon_frame));
	if (!buffer) {
		LOG_ERR("Malloc failed for send buffer");
		return;
	}

	buf_length = sizeof(struct nrf_wifi_fmac_rawpkt_info) + sizeof(beacon_frame);
	memcpy(buffer, &raw_tx_pkt, sizeof(struct nrf_wifi_fmac_rawpkt_info));

	memcpy(buffer + sizeof(struct nrf_wifi_fmac_rawpkt_info), beacon_frame, sizeof(beacon_frame));

	ret = sendto(sockfd, buffer, buf_length, 0,
			(struct sockaddr *)&sa, sizeof(sa));
	if (ret < 0) {
		LOG_ERR("Unable to send beacon frame");
		close(sockfd);
		free(buffer);
		return;
	}

	/* close the socket */
	close(sockfd);
	free(buffer);
}

int main(void)
{
	memset(&context, 0, sizeof(context));

	net_mgmt_init_event_callback(&wifi_shell_mgmt_cb,
				     wifi_mgmt_event_handler,
				     WIFI_SHELL_MGMT_EVENTS);

	net_mgmt_add_event_callback(&wifi_shell_mgmt_cb);

	net_mgmt_init_event_callback(&net_shell_mgmt_cb,
				     net_mgmt_event_handler,
				     NET_EVENT_IPV4_DHCP_BOUND);

	net_mgmt_add_event_callback(&net_shell_mgmt_cb);

	LOG_INF("Starting %s with CPU frequency: %d MHz", CONFIG_BOARD, SystemCoreClock/MHZ(1));
	k_sleep(K_SECONDS(1));

	LOG_INF("Static IP address (overridable): %s/%s -> %s",
		CONFIG_NET_CONFIG_MY_IPV4_ADDR,
		CONFIG_NET_CONFIG_MY_IPV4_NETMASK,
		CONFIG_NET_CONFIG_MY_IPV4_GW);

	wifi_set_mode();

#ifdef CONFIG_RAW_TX_PACKET_SAMPLE_CONNECTION_MODE
	while(1) {
		wifi_connect();
		
		while (!context.connect_result) {
			cmd_wifi_status();
			k_sleep(K_MSEC(STATUS_POLLING_MS));
		}
		
		if (context.connected) {
			wifi_send_raw_tx_packet();
			k_sleep(K_FOREVER);
		} else if (!context.connect_result) {
			LOG_ERR("Connection Timed Out");
		}
	}
#else
	wifi_set_channel();
	wifi_send_raw_tx_packet();
#endif

	return 0;
}
