#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
// p 185
int main(int argc, char* argv[]){
    int fd;
    int rtn;
    if (argc != 2)
    {
        printf("need a string\n");
        exit(1);
    }
    if (mkfifo("file.fifo", 0644) == -1)
    {
        if (errno == EEXIST)
        {
            printf("file.fifo exists\n");
        }
    }
    if (fd = open)
    {
        /* code */
    }
    
    
    
}