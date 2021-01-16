// name.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[])
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	struct hostent  *hp;
	char **p;
	unsigned int addr;
	char name[1024];

	//hp = gethostbyname("www.taobao.com");
	addr = inet_addr("211.67.48.2");
	hp = gethostbyaddr((char*)&addr,4, AF_INET );
	gethostname(name, sizeof(name));
	puts(name);

	if(hp == NULL)
	{
		exit(2);
	}
	for(p = hp->h_addr_list; *p!=0; p++)
	{
		struct in_addr in;
		char **q;
		memcpy(&in.s_addr, *p, sizeof(in.s_addr));
		printf("%s\t%s", inet_ntoa(in), hp->h_name);
		for(q=hp->h_aliases; *q!=0; q++)
			printf("%s", *q);
		putchar('\n');
	}


	getchar();
	return 0;
}

