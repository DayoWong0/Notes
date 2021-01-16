#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main(){
    int fd1, fd2, fd3;
    int num;
    char buf[20];
    fd1 = open("f1", O_RDWR | O_TRUNC);
    if(fd1 == -1){
        perror("open");
        exit(1);
    }
    printf("fd1 is %d\n", fd1);
    fd2 = open("f1", O_RDWR);
    if (fd2 == -1)
    {
        /* code */
        perror("open");
        exit(1);
    }
    printf("fd2 is %d\n", fd2);
    fd3 = dup(fd1);
    printf("fd3 is %d\n", fd3)

}
