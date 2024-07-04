/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <errno.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/types.h>
#include <zephyr/logging/log.h>

#include <dk_buttons_and_leds.h>

#include <zephyr/net/wifi.h>
#include <zephyr/net/wifi_mgmt.h>
#include <zephyr/net/net_mgmt.h>
#include <zephyr/net/net_if.h>
#include <zephyr/net/net_ip.h>
#include <zephyr/net/net_core.h>
#include <net/wifi_mgmt_ext.h>
#include <net/wifi_credentials.h>

/* STEP 2 - Include the header file for the socket API */
#include <zephyr/net/socket.h>

LOG_MODULE_REGISTER(Lesson3_Exercise1, LOG_LEVEL_INF);

#define EVENT_MASK (NET_EVENT_L4_CONNECTED | NET_EVENT_L4_DISCONNECTED)

/* STEP 3 - Define the hostname and port for the echo server */
#define MULTICAST_IP "232.10.11.12"//"117.203.102.216" //"232.10.11.12"//"nordicecho.westeurope.cloudapp.azure.com"
#define SERVER_PORT	"54545"//"54545"//"33060"//54545"//"2444"
#define MESSAGE_SIZE	256
#define MESSAGE_TO_SEND "Hello from nRF70 Series"
#define SSTRLEN(s)	(sizeof(s) - 1)
#define LOCAL_PORT "54545"
static struct net_mgmt_event_callback mgmt_cb;
static bool connected;
static K_SEM_DEFINE(run_app, 0, 1);

/* STEP 4.1 - Declare the structure for the socket and server address */
static int sock;
static struct sockaddr_storage server;
char ipv4_addr[NET_IPV4_ADDR_LEN];
/* STEP 4.2 - Declare the buffer for receiving from server */
static uint8_t recv_buf[MESSAGE_SIZE];

static void net_mgmt_event_handler(struct net_mgmt_event_callback *cb, uint32_t mgmt_event,
				   struct net_if *iface)
{
	if ((mgmt_event & EVENT_MASK) != mgmt_event) {
		return;
	}
	if (mgmt_event == NET_EVENT_L4_CONNECTED) {
		LOG_INF("Network connected");
		connected = true;
		dk_set_led_on(DK_LED1);
		k_sem_give(&run_app);
		return;
	}
	if (mgmt_event == NET_EVENT_L4_DISCONNECTED) {
		if (connected == false) {
			LOG_INF("Waiting for network to be connected");
		} else {
			dk_set_led_off(DK_LED1);
			LOG_INF("Network disconnected");
			connected = false;
		}
		k_sem_reset(&run_app);
		return;
	}
}

static int ip_resolve(void)
{
	/* STEP 5.1 - Call getaddrinfo() to get the IP address of the echo server */
	int err;
	struct addrinfo *result;
	struct addrinfo hints = {
		.ai_family = AF_INET,
		.ai_socktype = SOCK_DGRAM,
	};

	err = getaddrinfo(MULTICAST_IP, SERVER_PORT, &hints, &result);
	if (err != 0) {
		LOG_INF("getaddrinfo() failed, err: %d", err);
		return -EIO;
	}

	if (result == NULL) {
		LOG_INF("Error, address not found");
		return -ENOENT;
	}

	/* STEP 5.2 - Retrieve the relevant information from the result structure */
	struct sockaddr_in *server4 = ((struct sockaddr_in *)&server);

	server4->sin_addr.s_addr = ((struct sockaddr_in *)result->ai_addr)->sin_addr.s_addr;
	server4->sin_family = AF_INET;
	server4->sin_port = ((struct sockaddr_in *)result->ai_addr)->sin_port;

	/* STEP 5.3 - Convert the address into a string and print it */
	
	inet_ntop(AF_INET, &server4->sin_addr.s_addr, ipv4_addr, sizeof(ipv4_addr));
	LOG_INF("IPv4 address of server found %s", ipv4_addr);

	/* STEP 5.4 - Free the memory allocated for result */
	freeaddrinfo(result);

	return 0;
}


static int setup_socket(void)
{
	int err;
	struct sockaddr_in saddr = { 0 };
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY); // differs from sender
    saddr.sin_port = htons(54545);
	/*	int ret = net_addr_pton(AF_INET, "232.10.11.12", &daddr.sin_addr.s_addr);
    if (ret < 0) {
        printk("Invalid IP address\n");
        return;
    }*/
	/* STEP 6 - Create a UDP socket */
	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//IPPROTO_UDP//IPPROTO_IP
	if (sock < 0) {
		LOG_INF("Failed to create socket, err: %d, %s", errno, strerror(errno));
		return -errno;
	}
 int yes = 1;
    if (
        setsockopt(
            sock, SOL_SOCKET, SO_REUSEADDR, (char*) &yes, sizeof(yes)
        ) < 0
    ){
       LOG_INF("Reusing ADDR failed");
       return 1;
    }
    // bind to receive address
    if (bind(sock, (struct sockaddr*) &saddr, sizeof(saddr)) < 0) {
        LOG_INF("bind error");
        return 1;
    }

	LOG_INF("Successfully set up socket");

	return 0;
}

static void button_handler(uint32_t button_state, uint32_t has_changed)
{
	/* STEP 8 - Send a message every time button 1 is pressed */
	if (has_changed & DK_BTN1_MSK && button_state & DK_BTN1_MSK) {
	
	//	int err = send(sock, MESSAGE_TO_SEND, SSTRLEN(MESSAGE_TO_SEND), 0);
	int err = sendto(sock, MESSAGE_TO_SEND, SSTRLEN(MESSAGE_TO_SEND), 0,(struct sockaddr *)&server, sizeof(struct sockaddr_in));
		if (err < 0) {
			LOG_INF("Failed to send message, %d", errno);
			return;
		}
		LOG_INF("Successfully sent message: %s", MESSAGE_TO_SEND);
	}
}
static int join_multicast_group(struct net_if *iface)
{
    struct in_addr mcast_addr;
    if (net_addr_pton(AF_INET, MULTICAST_IP, &mcast_addr) < 0) {
        LOG_ERR("Invalid IP address format");
        return -1;
    }

    if (!net_if_ipv4_maddr_add(iface, &mcast_addr)) {
        LOG_ERR("Failed to add multicast address to interface");
        return -1;
    }

    return 0;
}
static bool check_multicast_join_status(struct net_if *iface, const char *ip_str) {
    struct in_addr mcast_addr;
    struct net_if_mcast_addr *mcast;

    // Convert IP string to binary form
    if (net_addr_pton(AF_INET, ip_str, &mcast_addr) < 0) {
        LOG_INF("Invalid IP address format\n");
        return false;
    }
	    if (!net_if_ipv4_maddr_add(iface, &mcast_addr)) {
        LOG_INF("Failed to add multicast address to interface");
        return -1;
    }
 

   mcast = net_if_ipv4_maddr_lookup(&mcast_addr, &iface);
    if (!mcast) {
        LOG_INF("Multicast address not found\n");
        return false;
    }
    char ip_mcast[INET_ADDRSTRLEN];  // Buffer to store the human-readable IP address
 // Convert the multicast address from binary to string format
    inet_ntop(AF_INET, &mcast->address.in_addr, ip_mcast, sizeof(ip_mcast));
  // Print the address
    LOG_INF("Multicast address is: %s", ip_mcast);


	net_ipv4_igmp_join(iface,&mcast_addr);
    return net_if_ipv4_maddr_is_joined(mcast);
}




int main(void)
{
	int received;
   struct sockaddr_in dsrc_addr; // Source address structure
   socklen_t addr_len = sizeof(dsrc_addr); // Length of the source address structure
 // struct in_addr mcast_addr;
 struct net_if *iface;


	if (dk_leds_init() != 0) {
		LOG_ERR("Failed to initialize the LED library");
	}

	/* Sleep to allow initialization of Wi-Fi driver */
	k_sleep(K_SECONDS(1));

	net_mgmt_init_event_callback(&mgmt_cb, net_mgmt_event_handler, EVENT_MASK);
	net_mgmt_add_event_callback(&mgmt_cb);

	LOG_INF("Waiting to connect to Wi-Fi");
	k_sem_take(&run_app, K_FOREVER);
    // Get default network interface
    iface = net_if_get_default();
   if (!iface) {
        printf("Error getting default interface\n");
        return;
    }

bool is_joined = check_multicast_join_status(iface, "232.10.11.12");
LOG_INF("Is 232.10.11.12 joined? %s\n", is_joined ? "Yes" : "No");

	if (dk_buttons_init(button_handler) != 0) {
		LOG_ERR("Failed to initialize the buttons library");
	}
 /*if (join_multicast_group(iface) != 0) {
        LOG_ERR("Failed to join multicast group");
        return -1;
    }*/

	/* STEP 9 - Resolve the server name and connect to the server */
	if (ip_resolve() != 0) {
		LOG_INF("Failed to resolve server name");
		return 0;
	}

	if (setup_socket() != 0) {
		LOG_INF("Failed to initialize client");
		return 0;
	}
	LOG_INF("Press button 1 on your DK to send your message");
	//LOG_INF("Listening on socket %d, port %s", sock, SERVER_PORT);
	  while (1) {
        //Listen for incoming messages using recvfrom 
      received = recvfrom(sock, recv_buf, MESSAGE_SIZE - 1, 0,(struct sockaddr *)&dsrc_addr, &addr_len);
/*received = recv(sock, recv_buf, sizeof(recv_buf), 0);
if (received > 0) {
    LOG_INF("Received data: %s\n", recv_buf);
}*/
        if (received < 0) {
            LOG_ERR("Socket error: %d, exit", errno);
            break;
        }

        if (received == 0) {
            LOG_ERR("Empty datagram");
            continue; // No need to break; empty datagrams may not be an error
        }
	// STEP 5.3 - Convert the address into a string and print it 
	char raddr_name[32] = { 0 };
	inet_ntop(AF_INET, &((struct sockaddr_in *)&dsrc_addr)->sin_addr, raddr_name, sizeof(raddr_name));

        recv_buf[received] = '\0'; // Null-terminate the received data
        LOG_INF("Data received from IP: %s, Message: %s",
                raddr_name, recv_buf); // Log the IP from which the data was received
    }

	close(sock);
	return 0;
}
