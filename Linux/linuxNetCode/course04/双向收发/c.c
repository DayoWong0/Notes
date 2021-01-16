#include <sys/types.h>      
#include<stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include <netdb.h>

int connectfd;
void * process_cli(void *arg)
{
	char buf[100];
	int len;
	while(1)
	{
		len = recv(connectfd, buf, 100, 0);
		if(len>=0)
		{
			buf[len] = 0;
			puts(buf);
		}
	}
}
int main(int argc,char *argv[])
{
	struct sockaddr_in server_addr;
	struct hostent *he;
	pthread_t pth;

	memset(&server_addr,0,sizeof(server_addr));
	
	if(argc!=2)
	{
		printf("Usage: %s <IP adress>\n",argv[0]);
		exit(1);
	}
	
	if((he=gethostbyname(argv[1]))==NULL)
	{
		exit(1);
	}

	if((connectfd=socket(AF_INET,SOCK_STREAM,0))==-1)  
	{
		printf("%s\n",strerror(errno));
	}	

	server_addr.sin_family=AF_INET;//协议族为ipv4
	server_addr.sin_port=htons(8888);//端口号为8888，htons()函数是将主机短字节序列转换为网络短字节序列
	server_addr.sin_addr=*((struct in_addr *)he->h_addr);
	if((connect(connectfd,(struct sockaddr *)&server_addr,sizeof(server_addr)))==-1)
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	pthread_create(&pth,NULL,process_cli,NULL);
	while(1){
		char buf[1024]={0};
		gets(buf);
		send(connectfd,buf,strlen(buf),0);//将缓冲区的内容发送给服务器
	}
	close(connectfd);//关闭已链接套接字
	return 0;
}
