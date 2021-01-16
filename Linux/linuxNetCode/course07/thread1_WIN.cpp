//thread1.cpp
#include <stdio.h>
#include <windows.h>
//#include <process.h> /* _beginthreadex, _endthreadex */
//�˵������̡�->�����á���ѡ����ӡ��еĶ���/��ģ���м��롰ws2_32.lib�� ��ֱ����Դ������ʹ������
//#pragma comment(lib,"ws2_32.lib")
unsigned WINAPI threadFunc(void * arg);

int main(int argc, char *argv[])
{
	HANDLE hThread; 
	DWORD threadID;
	//unsigned threadID;
	int param=5;
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)threadFunc,(void *)&param,0, &threadID);
	//hThread=(HANDLE)_beginthreadex(NULL,0, threadFunc,(void *)&param,0, &threadID);
	if(hThread==NULL)			
	{
		puts("CreateThread() fails \n");
		//puts("_beginthreadex() fails \n");
		return -1;
	}
//	WaitForSingleObject(hThread, INFINITE);
	Sleep(3000);
	puts("end of main");
	return 0;
}
unsigned WINAPI threadFunc(void * arg)
{
	int i;
	int cnt = *((int *)arg);
	for (i=0; i<cnt; i++)  
	{
		Sleep(1000);  puts("running thread");
	}
	return 0;
}
