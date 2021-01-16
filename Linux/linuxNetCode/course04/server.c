#include <sys/types.h>  
#include <sys/wait.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>


typedef struct ARG{
	int connectfd;
	struct sockaddr_in client_addr;
	//other things
}ARG;

//回射函数，将客户端发送的内容返回给客户端
void * process_cli(void *arg)
{
	ARG *arg1=((ARG *)arg);
	char buf[1024]={0};
	int num=0;
	printf("you got a connection from client's \n ip is %s\n port is %d\n",inet_ntoa(arg1->client_addr.sin_addr),htons(arg1->client_addr.sin_port));
	while((num=recv(arg1->connectfd,buf,sizeof(buf),0)))
	{
		buf[num]=0;
		while((num=send(arg1->connectfd,buf,strlen(buf),0)==-1))
		{	
		}
	}
	close(arg1->connectfd);
	free(arg);
	return NULL;
}

int main(int argc,char *argv[])
{
	int listenfd,connectfd;
	struct sockaddr_in server_addr,client_addr;
	pthread_t pth;
	
	memset(&server_addr,0,sizeof(server_addr));
	memset(&client_addr,0,sizeof(client_addr));
	

	//创建一个流式套接口：协议族为ipv4。
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)   //函数声明在#include <sys/types.h>      #include <sys/socket.h>中
	{
		printf("%s\n",strerror(errno));
	}
	
	int opt=1;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	
	//接下来的3行是做绑定前的参数处理：进程将该套接口的地址结构传递给内核
	server_addr.sin_family=AF_INET;//协议族为ipv4
	server_addr.sin_port=htons(8888);//端口号为8888，htons()函数是将主机短字节序列转换为网络短字节序列
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);//INADDR-ANY：0，内核选择ip地址
	if(bind(listenfd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1)//绑定端口信息
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
	socklen_t len=sizeof(client_addr);
	
	while(1)
	{
		//循环接受客户端的链接请求：该函数为阻塞函数，若没有客户端链接请求将会一直阻塞
		if((connectfd=accept(listenfd,(struct sockaddr *)&client_addr,&len))==-1)
		{
			printf("%s\n",strerror(errno));
			exit(1);
		}
		ARG *arg=(ARG *)malloc(sizeof(ARG));//传参数的时候必须是动态分配的，否则在高并发的时候arg的空间的数据会被覆盖
		arg->connectfd=connectfd;
		arg->client_addr=client_addr;
		if(pthread_create(&pth,NULL,process_cli,(void *)arg)!=0)//创建一个新线程
		{
			printf("%s\n",strerror(errno));
			exit(1);
		}
		pthread_detach(pth);//将新线程设置为可分离状态，即线程执行完后自动释放所有资源
		
/*
	该段是多进程服务器所需的系统调用
		if((pid=fork())>0)//父进程将执行该函数
		{
			close(connectfd);
			continue;
		}
		else if(pid==0)//子进程将执行该函数
		{
			close(listenfd);
			process_cli(connectfd,client_addr);
			exit(0);
		}
		else
		{
			printf("%s\n",strerror(errno));
			exit(1);
		}
*/
	}
	return 0;
}
