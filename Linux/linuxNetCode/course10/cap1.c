#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define BUFSIZE 1000
#define PCAP_ERRBUF_SIZ 200
void display(const u_char * packet,const size_t length);
void my_callback(u_char *none,const struct pcap_pkthdr * pkthdr,const u_char *packet)
{
	display((u_char *) packet,(size_t)(pkthdr->caplen));
	return;
}
int main(int argc,char**argv)
{
	int i;
	char *dev;
	char errbuf[PCAP_ERRBUF_SIZE];
	pcap_t * descr;
	const u_char *packet;
	struct pcap_pkthdr hdr;
	struct ether_header *eptr;
	struct bpf_program fp;
	bpf_u_int32 maskp;
	bpf_u_int32 netp;
	if(argc!=2){
		fprintf(stdout,"usage:%s\"filter program\"\n",argv[0]);
		return 0;
	}
	dev=pcap_lookupdev(errbuf);
	if(dev==NULL){
		fprintf(stderr,"%s\n",errbuf);
		exit(1);
	}
	printf("dev=%s",dev);
	fflush(stdout);
	pcap_lookupnet(dev,&netp,&maskp,errbuf);
	descr=pcap_open_live(dev,BUFSIZ,1,-1,errbuf);
	if(descr==NULL)
	{
		printf("pcap_open_live():%s\n",errbuf);
		exit(1);
	}
	if(pcap_compile(descr,&fp,argv[1],0,netp)==-1)
	{
		fprintf(stderr,"error calling pcap_compile\n");
		exit(1);
	}
	if(pcap_setfilter(descr,&fp)==-1) {
		fprintf(stderr,"error setting filter\n");
		exit(1);
	}
	pcap_loop(descr,-1,my_callback,NULL);
	return 0;
}

void display(const u_char *packet,const size_t length)
{
	u_long offset;
	int i,j,k;
	printf("packet[%lu bytes]:\n",(long unsigned int) length);
	if(length<=0){
		return;
	}
	i=0;
	offset=0;
	for(k=length/16;k>0;k--,offset+=16)
	{
		printf("%08X",(unsigned int)offset);
		for(j=0;j<16;j++,i++){
			if(j==8)
			{
				printf("%-%02X",packet[i]);
			}
			else printf("%02X",packet[i]);
		}
		printf("   ");
		i-=16;
		for(j=0;j<16;j++,i++){
			if((packet[i]<=' ')&&(packet[i]<=255)){
				printf("%c",packet[i]);
			}
			else printf(".");
		}
		printf("\n");
	}
	k=length-i;
	if(k<=0){
		return;
	}
	printf("%08X",(unsigned int)offset);
	for(j=0;j<k;j++,i++) {
		if(j==8){
			printf("-%02X",packet[i]);
		}
		else
			printf("%02X",packet[i]);
	}
	i-=k;
	for(j=16-k;j>0;j--){
		printf("  ");
	}
	printf("  ");
	for(j=0;j<k;j++,i++){
		if((packet[i]>=' ')&&(packet[i]<=255)){
			printf("%c",packet[i]);
		}
		else{
			printf(".");
		}
} printf("\n");return; }
