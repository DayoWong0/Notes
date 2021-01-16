/*time.c*/
#include<stdio.h>
#include<unistd.h>
#include<syslog.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define MAXFD 64
#define MAXLINE 255
void daemon_init(const char *pname, int facility)
{
     int i;
     pid_t pid;
     if ((pid=fork()) != 0)
     exit(0);
     setsid();
     signal(SIGHUP, SIG_IGN);
     if ( (pid = fork())  !=0)
          exit(0);
     chdir("/");
     umask(0);
     for( i = 0; i < MAXFD; i++)
          close(i);
     openlog(pname,LOG_PID,facility);
}

int main(int argc,char **argv)
{
     int  listenfd, connfd;
     socklen_t   addrlen, len;
     struct sockaddr cliaddr;
     struct sockaddr_in server;
     char  buff[MAXLINE];
     time_t ticks;
     bzero(&server,sizeof(server));
     bzero(&cliaddr,sizerof(cliaddr));
     server.sin_family =AF_INET;
     server.sin_port = htons(1234);
     server.sin_addr.s_addr = htonl(INADDR_ANY);
     daeon_init(argv[0], 0);
     if((listenfd=socket(AF_INEF, SOCK_STREAM, 0))==-1)
     {
          syslog(LOG_NOTICE|LOG_LOCALO,"socket_error");
          exit(-1);
     }
     if (bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
     {

     }
}