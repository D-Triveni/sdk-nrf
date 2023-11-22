/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/* @file
 * @brief Raw Tx Injection Shell 
 */

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(raw_tx_packet_shell, CONFIG_LOG_DEFAULT_LEVEL);

#include <zephyr/shell/shell.h>
#include <zephyr/net/socket.h>

struct nrf_wifi_fmac_rawpkt_info {
	/* Magic number to distinguish packet is raw packet */
	unsigned int magic_number;
	/* Data rate of the packet */
	unsigned char data_rate;
	/* Packet length */
	unsigned short packet_length;
	/* Mode describing if packet is VHT, HT, HE or Legacy */
	unsigned char tx_mode;
	/* Wi-Fi access category mapping for packet */
	unsigned char queue;
	/* reserved parameter for driver */
	unsigned char reserved;
};

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

static void wifi_send_raw_tx_pkts(const char *transmission_mode, int num_packets,
				  int delay, int rate_flags,
				  int data_rate, int queue_number)
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
	if (!iface) {
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
	raw_tx_pkt.data_rate = data_rate;
	raw_tx_pkt.packet_length = sizeof(beacon_frame);
	raw_tx_pkt.tx_mode = rate_flags;
	raw_tx_pkt.queue = queue_number;
	raw_tx_pkt.reserved = 0;

	buffer = malloc(sizeof(struct nrf_wifi_fmac_rawpkt_info) + sizeof(beacon_frame));
	if (!buffer) {
		LOG_ERR("Malloc failed for send buffer");
		return;
	}

	buf_length = sizeof(struct nrf_wifi_fmac_rawpkt_info) + sizeof(beacon_frame);
	memcpy(buffer, &raw_tx_pkt, sizeof(struct nrf_wifi_fmac_rawpkt_info));

	memcpy(buffer + sizeof(struct nrf_wifi_fmac_rawpkt_info),
				beacon_frame, sizeof(beacon_frame));

	if (num_packets == 0 && strcmp(transmission_mode, "fixed") == 0) {
		LOG_ERR("Can't send %d number of raw tx packets", num_packets);
		close(sockfd);
		free(buffer);
		return;
	}

	while (1) {
		if (strcmp(transmission_mode, "fixed") == 0 && num_packets == 0) {
			break;
		}

		ret = sendto(sockfd, buffer, buf_length, 0,
				(struct sockaddr *)&sa, sizeof(sa));
		if (ret < 0) {
			LOG_ERR("Unable to send beacon frame");
			close(sockfd);
			free(buffer);
			return;
		}

		if (strcmp(transmission_mode, "fixed") == 0 && num_packets > 0) {
			num_packets--;
		}

		k_sleep(K_MSEC(delay));
	}

	/* close the socket */
	close(sockfd);
	free(buffer);
}

static int cmd_wifi_send_packet(const struct shell *shell,
			  size_t argc,
			  const char *argv[])
{
	const char *mode = NULL;
	int num_packets = 0, delay, rate_flags, data_rate, queue_number;

	if (argc < 7) {
		shell_fprintf(shell, SHELL_WARNING,
			"Invalid arguments. Usage: %s <continuous/fixed> <num_packets> <delay>\n", argv[0]);
		return 1;
	}

	mode = argv[1];
	LOG_INF("TRIVENI: Priniting arg[1] : %s", mode);

	if (argc == 7) {
		num_packets = atoi(argv[2]);
	}

	delay = atoi(argv[argc - 5]); // Use the correct index based on the number of arguments
	rate_flags = atoi(argv[argc - 4]); // Use the correct index based on the number of arguments
	data_rate = atoi(argv[argc - 3]);  // Use the correct index based on the number of arguments
	queue_number = atoi(argv[argc - 2]);  // Use the correct index based on the number of arguments

	wifi_send_raw_tx_pkts(mode, num_packets, delay, rate_flags, data_rate, queue_number);

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
	raw_tx_cmds,
	SHELL_CMD(send,
		  NULL,
		  "To send a raw TX packet",
		  cmd_wifi_send_packet),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(raw_tx_packet,
		&raw_tx_cmds,
		"raw_tx_cmds (To send raw TX packets)",
		NULL);
