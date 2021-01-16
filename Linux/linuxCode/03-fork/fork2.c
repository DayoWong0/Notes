#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(){
    // 接受子进程 pid 的值
    pid_t id;
    int i;

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
        for (i = 0; i < 10; i++)
        {
        printf("I am child, my pid = %d\n", getpid());
        sleep(1);
        }
    }
    else
    {
        for ( i = 0; i < 10; i++)
        {
            printf("I am parent, my pid is %d \n", getpid());
            sleep(1);
        }
    }
    printf("%d print this sentence \n", getpid());
}