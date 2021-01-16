//echo_server.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
//菜单“工程”->“设置”的选项“连接”中的对象/库模块中加入“ws2_32.lib” 或直接在源代码中使用下面
#pragma comment(lib,"ws2_32.lib")

#define BUF_SIZE 1024
void ErrorHandling(char *message);

int main(int argc, char *argv[])
{
	WSADATA wsaData;
	SOCKET hServ_sock, hClnt_sock;
	SOCKADDR_IN servAdr, clntAdr;
	TIMEVAL timeout;
	fd_set reads, cpyReads;

	int adrSz;
	int strLen, fdNum, i;
	char buf[BUF_SIZE];

	if (argc !=2) 
	{
		printf("Usage: %s <port>\n", argv[0]);
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsaData)!=0) 
		ErrorHandling("WSAStartup() error");

	hServ_sock =socket(PF_INET, SOCK_STREAM, 0);
	if (hServ_sock== INVALID_SOCKET) 
		ErrorHandling("socket() error");
	memset(&servAdr,0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr= htonl(INADDR_ANY);
	servAdr.sin_port= htons(atoi(argv[1]));

	if (bind(hServ_sock, (SOCKADDR *)&servAdr, sizeof(servAdr))==SOCKET_ERROR) 
		ErrorHandling("bind() error");
	if (listen(hServ_sock, 5)==SOCKET_ERROR) 
		ErrorHandling("listen() error");

	FD_ZERO(&reads);
	FD_SET(hServ_sock, &reads);

	while(1) 
	{
		cpyReads=reads;
		timeout.tv_sec=5;
		timeout.tv_usec=5000;

		if ((fdNum= select(0, &cpyReads, 0, 0, &timeout))==SOCKET_ERROR)
			break;
		if (fdNum==0)
			continue;

		for (i=0; i<reads.fd_count; i++)
		{
			if(FD_ISSET(reads.fd_array[i], &cpyReads)) 
			{
				
				if (reads.fd_array[i]==hServ_sock) // connection request
				{
					adrSz = sizeof(clntAdr);
					hClnt_sock = accept(hServ_sock, (SOCKADDR *)&clntAdr, &adrSz);
					if (hClnt_sock==INVALID_SOCKET) 
						continue;
					else
					{
						FD_SET(hClnt_sock, &reads);
						printf("Connected client: %d \n", hClnt_sock);
					}
				}
				else // read message
				{
					strLen= recv(reads.fd_array[i], buf, BUF_SIZE-1, 0);
					if (strLen==0) //close request
					{
						FD_CLR(cpyReads.fd_array[i], &reads);
						closesocket(cpyReads.fd_array[i]);
						printf("Closed client: %d \n", cpyReads.fd_array[i]);
					}
					else
					{
						send(reads.fd_array[i], buf, strLen, 0);//echo!
					}
				}
			}
		}
	}
	closesocket(hServ_sock);
	WSACleanup();
	return 0;
}
void ErrorHandling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

