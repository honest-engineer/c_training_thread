#include    <stdio.h>
#include    <sys/wait.h>
#include    <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid, wpid;
    int stat;

    pid = fork();
    if (pid == 0) {
        // 子プロセスが実行する
        printf("[Child] PID:%ld PPID:%ld fork ret:%d\n", getpid(), getppid(), pid);
    } else if (pid > 0) {
        wpid = wait(&stat);
        //printf("Child exit PID:%d\n", wpid);
        // 親プロセスが実行する
        printf("[Parent] PID:%ld PPID:%ld fork ret:%d\n", getpid(), getppid(), pid);
    } else {
        printf("[Error] PID:%ld PPID:%ld fork ret:%d\n", getpid(), getppid(), pid);
    }
    // どちらも実行する
    printf("PID:%ld PPID:%ld fork ret:%d\n", getpid(), getppid(), pid);

    return 0;
}
