
#include <apue.h>
#include <myerr.h>
#include <fcntl.h>

void set_fl(int fd, int flags) /* flags are files status flags to turn on */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fnctl F_GETFL error");
    
    val |= flags;       // turn on flags

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}


void clr_fl(int fd, int flags) /* flags are files status flags to turn on */
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fnctl F_GETFL error");
    
    val &= ~flags;       // turn on flags

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}