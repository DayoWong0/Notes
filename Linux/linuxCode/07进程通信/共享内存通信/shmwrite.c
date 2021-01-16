//���������ڴ棬�����ڴ���д������
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSIZE 4096

int main(int argc,char * argv[])
{
	int shmid;
	key_t key;
	void * shmptr;
	key = ftok("/tmp",1);
	// 用于进程通信测试的数组 data[10]
	int data[10];
	if(key == -1){
		perror("ftok failed");
		exit(1);
	}
	shmid = shmget(key,SHMSIZE,IPC_CREAT | IPC_EXCL | 0600);
	if(shmid == -1){
		perror("shmget failed");
		exit(1);
	}
	printf("%d\n",shmid);
	shmptr = shmat(shmid,0,0);
	if(shmptr == (void *) -1){
		perror("shmat error");
		exit(1);
	}
	memcpy(shmptr,data,sizeof(data)*10);
	if(shmdt(shmptr) == -1){
		perror("shmdt failed");
		exit(1);
	}
	return 0;
}
