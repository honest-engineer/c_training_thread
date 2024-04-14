#include    <stdio.h>
#include    <unistd.h>

int main(int argc, char *argv[])
{
    printf("Hello world!\n");
    printf("PID:%d PPID:%d TID:%d", getpid(), getppid(), gettid());
    return 0;
}
