#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void fun(){
    printf("capture ctrl+c \r\n");
    exit(0);
}


int main(){
    signal(SIGINT,fun);
    while(1){
        printf("2s elapsed\r\n");  
        sleep(2000);   
    }
}