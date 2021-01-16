#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>

char *msg[] = {"one", "two", "three", "four", "five...\n"};
pthread_t tid[5];
sem_t can_print[6];

void *print_thr(void *p){
    int k;
    struct timespec tv;
    srand((int)&tv);
    tv.tv_sec = 0;
    tv.tv_nsec = (long)(rand()*1.0/RAND_MAX * 999999999);
    nanosleep(&tv, NULL);
    
    k = (int)p;

    sem_wait(&can_print[k]);
    printf("%s\n", msg[(int)p]);
    sem_post(&can_print[k+1]);
}

// PV 操作线程同步的多线程例子
int main(int argc, char **argv){
    int rtn;
    for (int i = 0; i < 6; i++)
    {
        sem_init(&can_print[i], 0, 0);
    }
    
    for (int k = 0; k < 5; k++)
    {
        rtn = pthread_create(&tid[k], NULL, &print_thr, (void*)k);
        if (rtn != 0)
        {
            perror("pthread_create error!");
            exit(1);
        }
    }
    sem_post(&can_print[0]);
    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("<done> \n");
    return 0;
}