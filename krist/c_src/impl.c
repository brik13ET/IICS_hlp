#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>          // close()
#include <string.h>          // strcpy, memset(), and memcpy()
#include <netdb.h>           // struct addrinfo
#include <sys/types.h>       // needed for socket(), uint8_t, uint16_t, uint32_t
#include <sys/socket.h>      // needed for socket()
#include <netinet/in.h>      // IPPROTO_ICMP, INET_ADDRSTRLEN
#include <netinet/ip.h>      // struct ip and IP_MAXPACKET (which is 65535)
#include <netinet/ip_icmp.h> // struct icmp, ICMP_ECHO
#include <arpa/inet.h>       // inet_pton() and inet_ntop()
#include <sys/ioctl.h>       // macro ioctl is defined
#include <bits/ioctls.h>     // defines values for argument "request" of ioctl.
#include <net/if.h>          // struct ifreq
#include <linux/if_ether.h>  // ETH_P_IP = 0x0800, ETH_P_IPV6 = 0x86DD
#include <linux/if_packet.h> // struct sockaddr_ll (see man 7 packet)
#include <net/ethernet.h>

#include <main_Socket.h>

struct sockaddr_ll sock;
int fd;

uint8_t
    eth_header[] = {
        0},
    ip_header[] = {0}, icmp_header[] = {0}, checksum[] = {0};

JNIEXPORT jboolean JNICALL Java_main_Socket_init(JNIEnv *env, jclass class, jstring arg)
{
    char *ifname = (*env)->GetStringUTFChars(arg, NULL);
    uint8_t if_index = = if_nametoindex(const char *ifname);
    sock = {
        sll_family = AF_PACKET,
        sll_protocol = 1, // ICMP
        sll_ifindex = if_index,
        sll_hatype =,
        sll_pkttype =,
        sll_halen =,
        sll_addr =,
    };
    fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

    (*env)->ReleaseStringUTFChars(arg, ifname);
}

JNIEXPORT void JNICALL Java_main_Socket_deinit(JNIEnv *env, jclass class)
{
    close(fd);
}

JNIEXPORT jint JNICALL Java_main_Socket_sendTo(JNIEnv *env, jclass class, jbyteArray arg)
{
    sendto(sd, frame, flen, 0, (struct sockaddr *)&device, sizeof(device));
}

JNIEXPORT jbyteArray JNICALL Java_main_Socket_recvFrom(JNIEnv *env, jclass class, jbyteArray arg1, jint arg2)
{
    recvfrom(sd, frame, flen, 0, (struct sockaddr *)&device, socklen_t * fromlen);
}
