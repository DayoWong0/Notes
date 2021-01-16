//ip.h
#ifndef _IP_H
#define _IP_H
#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define DEST_ADDR "127.0.0.1"
extern int errno;
char sendpacket[PACKET_SIZE];
char recvpacket[PACKET_SIZE];
int sockfd,datalen=56;
struct sockaddr_in dest_addr;
void send_packet();
void recv_packet();
unsigned short cal_chksum(unsigned short * addr,int len);
void showiphdr(struct ip *ip);
void onTerm();
#endif

int main(int argc,char *argv[])
{
	struct hostent *host;
	struct protoent *protocol;
	unsigned long inaddr=0L;
	if((protocol=getprotobyname("icmp"))==NULL)
	{
		perror("unknow protocol icmp");
		exit(1);
	}
	if((sockfd=socket(AF_INET,SOCK_RAW,protocol->p_proto))<0){
		perror("socket error");
		exit(2);
	}
	bzero(&dest_addr,sizeof(dest_addr));
	dest_addr.sin_family=AF_INET;
	inaddr=inet_addr(DEST_ADDR);
	memcpy((char*)&dest_addr.sin_addr,(char*)&inaddr,sizeof(inaddr));
	send_packet();
	recv_packet();
	return 0;
}
void send_packet()
{
	int i,packetsize;
	struct icmp *icmp;
	icmp=(struct icmp*)sendpacket;
	icmp->icmp_type=ICMP_ECHO;
	icmp->icmp_code=0;
	icmp->icmp_cksum=0;
	icmp->icmp_id=getpid();
	icmp->icmp_seq=1;
	packetsize=8+datalen; //数据包的大小
	icmp->icmp_cksum=cal_chksum((unsigned short*)icmp,packetsize);
	if((sendto(sockfd,sendpacket,packetsize,0,(struct sockaddr*)&dest_addr,sizeof(dest_addr)))<0){
		perror("send ICMP packets error\n");
		exit(3);
	}
	printf("send ICMP packet to %s\n",inet_ntoa(dest_addr.sin_addr));
}
unsigned short cal_chksum(unsigned short *addr,int len)
{
	int nleft=len;
	int sum=0;
	unsigned short *w=addr;
	unsigned short answer=0;
	while(nleft>1){
		sum+=*w++;
		nleft-=2;
	}
	if(nleft==1){
		*(unsigned char*)(&answer)=*(unsigned char*)w;
		sum+=answer;
	}
	sum=(sum>>16)+(sum&0xffff);
	sum+=(sum>>16);
	answer=~sum;
	return answer;
}
void recv_packet()
{
	int n,fromlen,packet_no;
	struct sockaddr_in from;
	struct ip *ip;
	struct icmp *icmp;
	signal(SIGALRM,onTerm);
	while(1)
	{
		fromlen=sizeof(from);
		alarm(MAX_WAIT_TIME);
		if((n=recvfrom(sockfd,recvpacket,sizeof(recvpacket),0,(struct sockaddr*)&from,&fromlen))<0){
			perror("Receive packet error");
			continue;
		}
		ip=(struct ip *)recvpacket;
		showiphdr(ip);
		printf("len:%d",ip->ip_hl);
		icmp=(struct icmp*)(recvpacket+4*ip->ip_hl);//取ICMP报头
		printf("ICMP TYPE=%d\n",icmp->icmp_type);
} }
void showiphdr(struct ip *ip)
{
	printf("------IP HEADER------\n");
	printf("version:%d\n",ip->ip_v);
	printf("header length:%d\n",ip->ip_hl);
	printf("type of service:%d\n",ip->ip_tos);
	printf("total length:%d\n",ip->ip_len);
	printf("identification:%d\n",ip->ip_id);
	printf("fragment offset field:%d\n",ip->ip_off);
	printf("time to live:%d\n",ip->ip_ttl);
	printf("protocol:%d\n",ip->ip_p);
	/*printf("checksum:%s\n",ip->ip_sum );*/
	printf("source IP address:%s\n",inet_ntoa(ip->ip_src));
	printf("destination IP address:%s\n",inet_ntoa(ip->ip_dst));
}

void onTerm()
{
	close(sockfd);
	exit(0);
}
