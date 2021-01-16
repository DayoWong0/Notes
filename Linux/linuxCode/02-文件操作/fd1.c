#include <fcntl.h>
int main(int argc, char const *argv[])
{
    int fd1, fd2, fd3;
    fd1 = open("f1", O_RDWR);
    fd2 = open("f2", O_RDWR);
    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);
    close(fd1);

    fd3 = open("f3", O_RDWR);
    printf("fd3=%d\n",fd3);

    close(fd2);
    close(fd3);
    return 0;
}
