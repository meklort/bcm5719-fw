#include "FreeRTOS.h"
#include <printf.h>

#define NO_SYS  0

#define LWIP_STATS 0

#define TCPIP_MBOX_SIZE (0)
#define TCPIP_THREAD_STACKSIZE (512)
#define TCPIP_THREAD_PRIO 2

#define LWIP_DHCP 1
#define MEM_SIZE    0x2000

#define MEMP_OVERFLOW_CHECK                 0
#define MEMP_SANITY_CHECK                   0
#define ARP_QUEUEING                        0
#define ETHARP_TRUST_IP_MAC                 0
#define LWIP_NETIF_HOSTNAME                 1
#define LWIP_NETIF_API                      0
#define LWIP_NETIF_STATUS_CALLBACK          0
#define LWIP_NETIF_LINK_CALLBACK            0
#define LWIP_NETIF_HWADDRHINT               1

#define MEMP_MEM_MALLOC 1
#define MEM_ALIGNMENT 8

// Temp to reduce size
#define LWIP_SOCKET 0
#define LWIP_IGMP 0
// #define TCP_STATS 0

#define IP_FRAG 1
#define IP_REASSEMBLY 1
#define LWIP_NOASSERT 1

//  #define TCP_MSS (1500 - 40) /* TCP_MSS = (Ethernet MTU - IP header size - TCP header size) TCP maximum segment size */
#define TCP_MSS (1500 - 40)
#define LWIP_SINGLE_NETIF               1
#define LWIP_HAVE_LOOPIF 0
#define LWIP_NETIF_TX_SINGLE_PBUF       1

#undef LWIP_DEBU

#define LWIP_TCPIP_CORE_LOCKING 1

// #define ETH_PAD_SIZE 2

// #define CHECKSUM_GEN_IP 0
// #define CHECKSUM_GEN_UDP 0
// #define CHECKSUM_GEN_TCP 0

#define LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED 1
#define HTTPD_POLL_INTERVAL 1

// #define CHECKSUM_CHECK_IP   0
// #define CHECKSUM_CHECK_UDP  0
// #define CHECKSUM_CHECK_TCP  0
// #define CHECKSUM_CHECK_ICMP 0
// #define CHECKSUM_CHECK_ICMP6    0
