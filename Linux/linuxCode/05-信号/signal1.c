#include <stdio.h>
char m = 'A';
int num = 0;
void handler(int i);
void signal(SIGINT, handler);

// 此代码有问题
void main(){

    signal(SIGINT, handler);
    while (1)
    {
        if (num % 2 == 0 )
        {
            printf("%d\n", m);
        }
        else
        {
            printf("%c\n", m);
        }
        sleep(1);   
            
    } 
}

void handler(int i){
    num ++;
}