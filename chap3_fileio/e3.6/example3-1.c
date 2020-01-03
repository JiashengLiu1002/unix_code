
#include "apue.h"

int main(void)
{
    if (lseek(STDIN_FILENO, 5, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    
    _exit(0);
}


