// tserv.c.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include<time.h>
#include <stdlib.h>
#include<stdio.h>
#include<winsock2.h>
#include<string.h>
#include
#define BUFLEN 255
void getcurtime(char *curtime)
{
	time_t tm;
	time(&tm);
	snprintf(curtime,BUFLEN,"%s\n",ctime(&tm));
}

int _main(int argc, char* argv[])
{
	WSADATA wsaData;
	struct sockaddr_in peeraddr;
	int sockfd ,on = 1;
	int num,i;
	char msg[BUFLEN+1];
	if(argc!=3)
	{
		printf("usage :%s<ip address><port>\n",argv[0]);
		exit(0);
	}
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		fprintf(stderr,"socket creating error in tserv.c\n");
		exit(1);
	}
	setsockpt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(int));
	memset(&peeraddr,0,sizeof(struct sockaddr_in));
	peeraddr.sin_family = AF_INET;
	if(inet_pton(AF_INET,argv[1],&peeraddr.sin_addr)<=0)
	{
		printf("Wrong dest IP address\n");
		exit(0);
	}
	peeraddr.sin_port = htons(atoi(argv[2]));
	for(;;)
	{
		fetcurtime(msg);
		int a;
		a = sendto(sockfd,msg,strlen(msg),0,(struct sockaddr*)&peeraddr,sizeof(struct sockaddr_in));
		printf("%d",a);
		fflush(stdout);
		sleep(3);
	}
}

