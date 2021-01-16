#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(){
    int fd;
    char buf[100];
    int len, num;
    struct sockaddr_in serveraddr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9999);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (fork() > 0 )
    {
        /* code */
    }
    
    while (1)
    {
        fgets(buf, 100, stdin);
        sendto(fd, buf, strlen(buf), 0, (struct sockaddr*)&server, sizeof(server));
    }
    else
    {
        char rbuf[100];
        len = sizeof(server);
        num = recvfrom(fd, buf, 100, 0, (struct sockaddr*)&server, ??)
    }
    
    

    strcpy(buf, "hello");
    printf("over\n\r");
    close(fd);
}
