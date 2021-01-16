//�ӹ����ڴ��ж�ȡ����
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(int argc,char * argv[]) 
{
    int shmid;
    key_t key;
    void * shmptr; 
    int data[10];
    key = ftok("/tmp",1);
    shmid = shmget(key,SHMSIZE,SHM_R |SHM_W);
    if(shmid == -1){ 
        perror("shmget failed");
        exit(1);
    }
    shmptr = shmat(shmid,0,0);
    if(shmptr == (void *) -1){ 
        perror("shmat error");
        exit(2);
    }
    memcpy(data,shmptr,sizeof(data)*10);
    if( shmdt(shmptr) == -1){ 
        perror("shmdt failed");
        exit(3);
    }
    return 0;
}
