#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int global;
char buf[] = "write information to stdout\n";
int main(int argc, char* argv[]){
    int var = 0;
    pid_t pid;
    if (write(STDOUT_FILENO, buf, strlen(buf) <0 ))
    {
        /* code */
        perror("write error");
    }
    printf("before fork\n");
    if((pid=fork()) <0 ){
        perror("fork error");
    }
    
    else if (pid == 0)
    {
        // 子进程修改全局变量
        /* code */
        global ++;
        var ++;
    }
    else
    {
        /* code */
        sleep(1);
    }
    printf("pid = %d global = %d var = %d\n", getpid(), global, var);
    exit(0);
    
}