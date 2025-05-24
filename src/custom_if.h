#ifndef CUSTOM_IF_H
#define CUSTOM_IF_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* 常量定义 */
#define IFNAMSIZ 16

/* 硬件地址结构体 */
struct sockaddr_hw {
    unsigned short  sa_family;
    unsigned char   sa_data[14];
};

/* ifreq 结构体定义，兼容 masscan 代码需求 */
struct ifreq {
    char ifr_name[IFNAMSIZ];
    union {
        struct sockaddr ifr_addr;
        struct sockaddr ifr_dstaddr;
        struct sockaddr ifr_broadaddr;
        struct sockaddr ifr_netmask;
        struct sockaddr_hw ifr_hwaddr;
        short           ifr_flags;
        int             ifr_ifindex;
        int             ifr_metric;
        int             ifr_mtu;
    };
    /* 别名，与 glibc 兼容 */
    #define ifr_ifru         ifr_addr
    #define ifru_hwaddr      ifr_hwaddr
};

/* ioctl 命令常量 */
#ifndef SIOCGIFADDR
#define SIOCGIFADDR 0x8915
#endif

#ifndef SIOCGIFHWADDR
#define SIOCGIFHWADDR 0x8927
#endif

#ifndef SIOCGIFINDEX
#define SIOCGIFINDEX 0x8933
#endif

#endif /* CUSTOM_IF_H */
