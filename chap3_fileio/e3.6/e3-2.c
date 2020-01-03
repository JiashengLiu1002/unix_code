
#include "apue.h"
#include "myerr.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
        err_sys("create error");
        // printf("create error");
        // exit(1);
    }

    if (write(fd, buf1, 10) != 10)
    {
        err_sys("buf1 write error");
        // printf("buf1 write error");
        // exit(1);
    }
    // now offset = 10
    int error = 0;
    if ((error = lseek(fd, 16384, SEEK_SET)) == -1)
    {
        err_sys("lseek error");
        printf("err=%d", error);
        // printf("lseek error");
        // exit(1);
    }
    // offset now = 16384
    if (write(fd, buf2, 10) != 10)
    {
        err_sys("buf2 write error");
        // printf("buf2 write error");
        // exit(1);
    }

    exit(0);
}