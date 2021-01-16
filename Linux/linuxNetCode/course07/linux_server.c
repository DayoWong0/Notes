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

//���亯�������ͻ��˷��͵����ݷ��ظ��ͻ���
void * process_cli(void *arg)
{
	int i=0;
	int max=-1;
	int err;
	fd_set fdset;
	struct timeval timeout;//���õĳ�ʱʱ��
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
				FD_SET(connect_host.fd[i],&fdset);//���������׽��ּ��뵽������������
				if(connect_host.fd[i]>max)
				max=connect_host.fd[i];
			}
		}
		err=select(max+1,&fdset,NULL,NULL,&timeout);//��ѯ�ļ�������������׽ӿ�
		switch(err)
		{
			case 0:;break;//��ʱ��
			case -1:;break;//������
			default:
				for(i=0;i<128;i++)
				{
					if(connect_host.fd[i]!=-1)
					{
						if(FD_ISSET(connect_host.fd[i],&fdset))//�쿴���׽����Ƿ���������������
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
		if((connectfd=accept(listenfd,(struct sockaddr *)&client_addr,&len))==-1)//������������
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
		connect_host.fd[i]=-1;//����¼TCP���ӵ�������״̬
	}
	connect_host.num=0;//��¼�����ӵĸ���
	
	//����һ����ʽ�׽ӿڣ�Э����Ϊipv4��
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1)   //����������#include <sys/types.h>      #include <sys/socket.h>��
	{
		printf("%s\n",strerror(errno));
	}
	
	int opt=1;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	
	//��������3��������ǰ�Ĳ����������̽����׽ӿڵĵ�ַ�ṹ���ݸ��ں�
	server_addr.sin_family=AF_INET;//Э����Ϊipv4
	server_addr.sin_port=htons(8888);//�˿ں�Ϊ8888��htons()�����ǽ��������ֽ�����ת��Ϊ������ֽ�����
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);//INADDR-ANY��0���ں�ѡ��ip��ַ
	if(bind(listenfd,(struct sockaddr *)&server_addr,sizeof(server_addr))==-1)//�󶨶˿���Ϣ
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	//���׽���ת��Ϊ�����׽��� ������closed״̬ת��Ϊlisten״̬
	if(listen(listenfd,128)==-1)//����������������������Ϊ128�������ֿ����������
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	
	if(pthread_create(&pth,NULL,process_connect,(void *)&listenfd)!=0)//����һ�����߳�,���߳�ר�Ÿ��������������
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	
	if(pthread_create(&pth1,NULL,process_cli,NULL)!=0)//����һ�����̣߳����̸߳���������
	{
		printf("%s\n",strerror(errno));
		exit(1);
	}
	pthread_join(pth,NULL);//�ȴ��̵߳Ľ���
	pthread_join(pth1,NULL);//�����ĵȴ��̵߳Ľ���
		

	return 0;
}
