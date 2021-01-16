#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// 这代码有问题 最后一个 printf 不输出，待解决
int main(){
    pid_t pid;
    int fd;
    char *info = "hello world";
    char buf[64] = {0};
    int nBytes;
    fd = open("file,", O_RDWR | O_CREAT, 0644);
    if (fd <0 )
    {
        perror("open file failed");
        exit(1);
    }

    printf("before fork \n");
    if (pid = fork() < 0)
    {
        perror("fork error");
    }
    else if (pid == 0)
    {
        /* code */
        if ((nBytes = write(fd, info, strlen(info))) <0)
        {
            /* code */
            perror("write failed");
        }
        exit(0);
    }
    
    else
    {
        sleep(1);
        lseek(fd, 0, SEEK_SET);
        if ((nBytes = read(fd, buf, 64)) <0)
        {
            perror("read failed");
        }
        printf("%s\n", buf);
    }
    exit(0);
    
    

    
}