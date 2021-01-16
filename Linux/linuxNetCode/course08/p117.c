#include <syslog.h>
#include <unistd.h>
int main()
{
    openlog("here",LOG_PID,LOG_USER);
    syslog(LOG_INFO|LOG_LOCAL2,"OK");
    closelog();
}
