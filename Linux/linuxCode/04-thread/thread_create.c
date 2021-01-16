#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fun();
// gcc -o thread_create thread_create.c  -lpthread
int main(int argc, char **argv){
    int rtn;
    pthread_t thread_id;
    rtn = pthread_create(&thread_id, NULL, &thread_fun, NULL);
    if (rtn != 0)
    {
        /* code */
        perror("pthread_create error!");
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("in main: print in main");
        sleep(1);
    }
    return 0;
}

void *thread_fun(){
    pthread_t new_thid;
    new_thid = pthread_self();
    for (int i = 0; i < 10; i++)
    {     
        printf("this is a new thread, thread ID is %u\n", new_thid);
        printf("---end---\n");
        sleep(1);
    }

}