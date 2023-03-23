
#include <zephyr/logging/log.h>
#include <zephyr/net/net_ip.h>

#define MSG_CONFIRM	0x800
#define ICMP_ECHO	8
#define STDOUT_FILENO   1
#define F_OK    0

extern struct wpa_global *global;

#include <src/utils/common.h>
#include <common/wpa_ctrl.h>
#include <wpa_supplicant/config.h>
typedef unsigned char u8_t;
typedef unsigned long u32_t;
//#include <wpa_supplicant/wpa_supplicant_i.h>
#define CERTIFICATES_PATH    "/etc/wpa_supplicant"
#define inet_addr(cp)                   ipaddr_addr(cp)
#define ip4_addr_get_u32(src_ipaddr) ((src_ipaddr)->addr)
//#define IPADDR_NONE         ((u32_t)0xffffffffUL)


struct ip4_addr {
	u32_t addr;
};
#define lwip_htonl(x) (x)
#define ip4_addr_set_u32(dest_ipaddr, src_u32) ((dest_ipaddr)->addr = (src_u32))
typedef struct ip4_addr ip4_addr_t;
