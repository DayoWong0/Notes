#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFSIZE 15
void main()  
{
	int fd = -1;
	ssize_t nread;
	char buf[BUFSIZE]; 
	if((fd = open("record",O_RDONLY))==-1) 
	{
		perror("open file error"); 
		exit(1);
	}
    lseek(fd, 100, SEEK_SET);
	nread = read(fd, buf, sizeof(buf));
	while (nread > 0)
	{
        printf(nread);
	}
	close(fd);
	return;
}
