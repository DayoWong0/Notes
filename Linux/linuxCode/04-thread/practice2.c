#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int x = 0;
int y = 0;
void thread1(void){
    printf("this is pthread1. the sentense 1 \n");
    y = 7;
    sleep(1);
    printf("this is pthread1. the sentense 2 \n");
    x = x + y;
}

void thread2(void){
    printf("this is pthread2. the sentense 1 \n");
    x = 4;
    sleep(1);
    printf("this is pthread2. the sentense 2 \n");
    y = 8 + y;
}

int main(void){
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void *)thread1, NULL);
    pthread_create(&id2, NULL, (void *)thread2, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    printf("x = %d, y = %d\n", x, y);

}