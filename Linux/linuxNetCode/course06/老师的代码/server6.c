#include <sys/types.h>      
#include<stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int listenfd,connectfd;	
	struct sockaddr_in6 server_addr,client_addr;
	char ipbuf[100];
	
	memset(&server_addr,0,sizeof(server_addr));
	memset(&client_addr,0,sizeof(client_addr));

	if((listenfd=socket(AF_INET6,SOCK_STREAM,0))==-1)
	{
		printf("%s\n",strerror(errno));
	}
	
	int opt=1;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	
	server_addr.sin6_family=AF_INET6;
	server_addr.sin6_port=htons(8888);
	server_addr.sin6_addr=in6addr_any;
	if(bind(listenfd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	//将套接字转换为被动套接字 即：从closed状态转变为listen状态
	if(listen(listenfd,128)==-1)//设置请求队列中最大链接数为128，次数字可以随便设置
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	//接受客户端的链接请求：该函数为阻塞函数，若没有客户端链接请求将会一直阻塞
	socklen_t len=sizeof(client_addr);
	if((connectfd=accept(listenfd,(struct sockaddr *)&client_addr,&len))==-1)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	inet_ntop(AF_INET6, &client_addr.sin6_addr, ipbuf, sizeof(client_addr.sin6_addr));
	printf("you got a connection from client's \n ip is %s\n port is %d\n",ipbuf,htons(client_addr.sin6_port));
	int sendnum=0;
	while((sendnum=send(connectfd,"welcome",8,0)==-1))
	{
	}
	puts("send welcome to client\n\r");
	close(connectfd);//关闭已链接的套接字
	close(listenfd);//关闭监听的套接字
	return 0;
}
