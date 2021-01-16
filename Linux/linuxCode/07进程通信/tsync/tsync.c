#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *msg[] = {"one", "two", "three", "four", "five...\n"};
pthread_t tid[5];

void *print_thr(void *p){
    struct timespec tv;
    srand((int)&tv);
    tv.tv_sec = 0;
    tv.tv_nsec = (long)(rand()*1.0/RAND_MAX * 999999999);

    nanosleep(&tv, NULL);

    printf("%s\n", msg[(int)p]);
}

// 没有线程同步的多线程
int main(int argc, char **argv){
    int rtn;

    for (int k = 0; k < 5; k++)
    {
        rtn = pthread_create(&tid[k], NULL, &print_thr, (void*)k);
        if (rtn != 0)
        {
            perror("pthread_create error!");
            exit(1);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("<done> \n");
    return 0;
}