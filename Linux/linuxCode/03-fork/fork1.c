#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(){
    // 接受子进程 pid 的值
    pid_t id;

    // 系统调用
    id = fork();

    // 进程创建失败，返回值为 -1
    if (id<0)
    {
        perror("fork");
        exit(1);
    }
    // 创建成功 id = 0，为子进程
    else if (id==0)
    {
        printf("I am child, my pid = %d\n", getpid());
    }
    else
    {
        printf("I am parent, my pid is %d \n", getpid());
    }
    printf("%d print this sentence \n", getpid());
}