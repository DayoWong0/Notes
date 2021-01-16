#include <sys/types.h>      
#include<stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include <netdb.h>


int main(int argc,char *argv[])
{
	int connectfd;
	struct sockaddr_in6 server_addr;
	struct hostent *he;
	
	memset(&server_addr,0,sizeof(server_addr));
	
	if(argc!=2)
	{
		printf("Usage: %s <IP adress>\n",argv[0]);
		exit(1);
	}

	inet_pton(AF_INET6, argv[1], &server_addr.sin6_addr);
	

	if((connectfd=socket(AF_INET6,SOCK_STREAM,0))==-1) 
	{
		printf("%s\n",strerror(errno));
	}

	server_addr.sin6_family=AF_INET6;
	server_addr.sin6_port=htons(8888);
	
	if((connect(connectfd,(struct sockaddr *)&server_addr,sizeof(server_addr)))==-1)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	char buf[1024]={0};
	int num=0;
	while((num=recv(connectfd,buf,sizeof(buf),0))!=0)
	{
		buf[num]=0;
		puts(buf);
	}
	close(connectfd);//关闭已链接套接字
	return 0;
}
