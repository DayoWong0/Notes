#include <stdio.h>
char m = 'A';
int num = 0;

void main(){
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