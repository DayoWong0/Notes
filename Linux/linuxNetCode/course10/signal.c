#include <stdio.h>
#include <signal.h> 
#include <unistd.h> 
void signal_handler(int  signo)  
{ 
    printf("Have caught  signal N.O.%d\n",signo); 
} 

int  main(void) 
{ 
   printf("process id is %d\n",getpid()); 
   signal(SIGINT,signal_handler); 	//ctrl + c
   signal(SIGQUIT,signal_handler);  /* ctrl + \ */
   getchar(); 
} 
