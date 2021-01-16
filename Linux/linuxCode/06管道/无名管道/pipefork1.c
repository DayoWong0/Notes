#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
// 父子进程管道通信
int main(){
    pid_t pid;
    char data[32] = "hello";
    char buf[32] = {0};
    int fds[2];
    if (pipe(fds) == 0)
    {
        pid = fork();
        // 父进程
        if (pid == 0)
        {
            close(fds[0]);
            write(fds[1], data, strlen(data));
            exit(0);
        }
        // 子进程
        else if (pid > 0)
        {
            wait(NULL);
            close(fds[1]);
            read(fds[0], buf, sizeof(buf));
            printf("%s\n", buf);
        }
        return 0;
    }
}