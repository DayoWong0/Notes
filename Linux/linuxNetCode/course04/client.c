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
	struct sockaddr_in server_addr;
	struct hostent *he;
	
	memset(&server_addr,0,sizeof(server_addr));
	
	if(argc!=2)
	{
		printf("Usage: %s <IP adress>\n",argv[0]);
		exit(1);
	}
	
	//域名到IP地址的转换，同时可以得到服务器的各种信息：如：www.baidu.com到0.0.0.0类型IP地址的转换
	if((he=gethostbyname(argv[1]))==NULL)
	{
		exit(1);
	}
	
	//创建一个流式套接口：协议族为ipv4。
	if((connectfd=socket(AF_INET,SOCK_STREAM,0))==-1)   //函数声明在#include <sys/types.h>      #include <sys/socket.h>中
	{
		printf("%s\n",strerror(errno));
	}
	

/*	
	该注释内容可存在，也可以没有：加上代表已绑定端口号的套接字
	server_addr.sin_family=AF_INET;//协议族为ipv4
	server_addr.sin_port=htons(1234);//端口号为8888，htons()函数是将主机短字节序列转换为网络短字节序列
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);//INADDR-ANY：0，内核选择ip地址
	if(bind(connectfd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1)//绑定端口信息
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	memset(&server_addr,0,sizeof(server_addr));
*/	
	server_addr.sin_family=AF_INET;//协议族为ipv4
	server_addr.sin_port=htons(8888);//端口号为8888，htons()函数是将主机短字节序列转换为网络短字节序列
	server_addr.sin_addr=*((struct in_addr *)he->h_addr);//he->h_addr是char * 类型的，但并非指向一个字符串，指向struct in_addr类型的地址
	if((connect(connectfd,(struct sockaddr *)&server_addr,sizeof(server_addr)))==-1)//链接服务器套接字，经历三次握手
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	char buf[1024]={0};
	int num=0;
	printf("请输入将发送给服务器的内容：\n");
	gets(buf);
	num=send(connectfd,buf,strlen(buf),0);//将缓冲区的内容发送给服务器
	num=recv(connectfd,buf,sizeof(buf),0);
	buf[num]=0;
	puts(buf);
	close(connectfd);//关闭已链接套接字
	return 0;
}
