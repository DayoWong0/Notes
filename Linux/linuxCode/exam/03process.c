#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(){
    pid_t id;
    int status;
    time_t nowtime;
    struct tm *current_time;
    id = fork();
	if(id<0){
        perror("fork error");
        exit(1); 
        }
    else if(id==0){  
        sleep(3);
        printf("I am child, my pid=  %d\n",getpid());  
    }
    else{
        id = waitpid(id, &status, 0);
        time(&nowtime);
        current_time = localtime(&nowtime);
        printf("child process id:%d have ended at %d: %d: %d\n", 
        id,
        current_time->tm_hour, 
        current_time->tm_min, 
        current_time->tm_sec
        );  
    }
    return 0;
}
