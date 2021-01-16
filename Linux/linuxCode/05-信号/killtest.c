// 子进程向父进程发送信号
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void sig_handler(int sig){
    printf("begin signal handler ...\n");
    switch (sig)
    {
    case SIGUSR1:
        printf("SIGUSR1 is caught\n");
        break;
    
    default:
    printf("other signal is caught\n");
        break;
    }
}

int main(void){
    pid_t pid;
    if (signal(SIGUSR1, sig_handler) == SIG_ERR){
        /* code */
        printf("signal(SIGUSR1) error\n");
        exit(1);
    }
    pid = fork();
    if (pid == 0)
    {
        /* code */
        if (kill(getppid(), SIGUSR1) == -1)
        {
            /* code */
            printf("kill() failed\n");
            exit(2);
        }    
    }
    else if (pid > 0)
    {
        /* code */
        wait(NULL);
    }
    return 0;
}