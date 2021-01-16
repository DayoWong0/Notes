// #include"stdafx.h"
// #include<time.h>
// #include<winsock2.h>
// #include <stdlib.h>
// #include<stdio.h>
// #include<string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#define BUFLEN 255
int main(int argc, char** argv){
    struct sockaddr_in localaddr;
    int sockfd, n;
    struct ip_mreq mcaddr;
    char msg[BUFLEN + 1];
    if (argc <3)
    {
        printf("usage: %s <multicast> <port>\n", argv[0]);
        exit(0);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        /* code */
        fprintf(stderr, "sockert creating error in tcli.c\n");
        exit(1);
    }
    memset(&localaddr, 0, sizeof(struct sockaddr_in));
    localaddr.sin_port = htons(atoi(argv[2]));
    localaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (inet_pton(AF_INET, "222.18.113.171", &mcaddr.imr_interface) <= 0)
    // 设置本读 IP地址
    {
        perror("failure");
        exit(0);
    }
    // 加入那个多播组又命令行参数给出
    if (inet_pton(AF_INET, argv[1], &mcaddr.imr_multiaddr) <= 0)
    {
        printf("Wring multcast IP address\n");
        exit(0);
    }
    printf("ip: %s", inet_ntoa(mcaddr.imr_multiaddr));
    fflush(stdout);
    if (setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mcaddr, sizeof(struct ip_mreq)) < 0 ){
        // 加入多播分组
        perror("setsockopt error in mtcli.c, join multicast failed\n");
        exit(4);
    }
    if (bind(sockfd, (struct sockaddr *)&localaddr, sizeof(struct sockaddr_in)) < 0){
        /* code */
        fprintf(stderr, "bind error in tcli.c\n");
        exit(2);
    }
    n = read(sockfd, msg, BUFLEN);
    if (n == -1)
    {
        fprintf(stderr, "read error in tcli.c\n");
        exit(3);
    }
    else
    {
        msg[n] = 0;
        printf("%s", msg);
    }   
}