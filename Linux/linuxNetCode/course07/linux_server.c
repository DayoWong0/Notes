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

struct{
	int fd[128];
	int num;
}connect_host;

typedef struct ARG{
	int connectfd;
	struct sockaddr_in client_addr;
	//other things
}ARG;

//回射函数，将客户端发送的内容返回给客户端
void * process_cli(void *arg)
{
	int i=0;
	int max=-1;
	int err;
	fd_set fdset;
	struct timeval timeout;//设置的超时时间
	char buf[1024]={0};
	
	while(1)
	{
		timeout.tv_sec=1;
		timeout.tv_usec=0;
		
		FD_ZERO(&fdset);
		for(i=0;i<128;i++)
		{
			if(connect_host.fd[i]!=-1)
			{
				FD_SET(connect_host.fd[i],&fdset);//将待检测的套接字加入到描述符集合中
				if(connect_host.fd[i]>max)
				max=connect_host.fd[i];
			}
		}
		err=select(max+1,&fdset,NULL,NULL,&timeout);//轮询的检测满足条件的套接口
		switch(err)
		{
			case 0:;break;//超时了
			case -1:;break;//出错了
			default:
				for(i=0;i<128;i++)
				{
					if(connect_host.fd[i]!=-1)
					{
						if(FD_ISSET(connect_host.fd[i],&fdset))//察看该套接字是否在描述符集合中
						{
							int num=0;
							while((num=recv(connect_host.fd[i],buf,sizeof(buf),0)))
							{
								buf[num]=0;
								while((num=send(connect_host.fd[i],buf,strlen(buf),0)==-1))
								{	
								}
							}
							close(connect_host.fd[i]);
							connect_host.fd[i]=-1;
							connect_host.num--;	
						}
					}
				}
			;break;
		}
	}
	
	return NULL;
}

void * process_connect(void *argv)
{
	int listenfd=*((int *)argv);
	int connectfd;
	int i=0;
	struct sockaddr_in client_addr;
	socklen_t len=sizeof(client_addr);
	
	while(1)
	{
		if((connectfd=accept(listenfd,(struct sockaddr *)&client_addr,&len))==-1)//接受链接请求
		{
			printf("%s\n",strerror(errno));
			exit(1);
		}
		printf("you got a connection from client's \n ip is %s\n port is %d\n",inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port));
		for(i=0;i<128;i++)
		{
			if(connect_host.fd[i]==-1)
			{
				connect_host.fd[i]=connectfd;
				connect_host.num++;
				break;
			}
		}
		
	
	}
	
}


int main(int argc,char *argv[])
{
	int listenfd;
	struct sockaddr_in server_addr,client_addr;
	pthread_t pth,pth1;
	
	memset(&server_addr,0,sizeof(server_addr));
	memset(&client_addr,0,sizeof(client_addr));
	
	int i=0;
	for(i=0;i<128;i++)
	{
		connect_host.fd[i]=-1;//将记录TCP链接的描述的状态
	}
	connect_host.num=0;//记录已链接的个数
	
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
	
	
	if(pthread_create(&pth,NULL,process_connect,(void *)&listenfd)!=0)//创建一个新线程,该线程专门负责接受链接请求
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	if(pthread_create(&pth1,NULL,process_cli,NULL)!=0)//创建一个新线程，该线程负责处理请求
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	pthread_join(pth,NULL);//等待线程的结束
	pthread_join(pth1,NULL);//阻塞的等待线程的结束
		

	return 0;
}
