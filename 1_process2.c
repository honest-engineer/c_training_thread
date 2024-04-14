#include    <stdio.h>
#include    <sys/wait.h>
#include    <unistd.h>

int main(int argc, char *argv[])
{
    pid_t pid, wpid;
    int stat;
    int a = 0;

    pid = fork();
    if (pid == 0) {
        // 子プロセスが実行する
        a++;
        printf("[Child] PID:%ld PPID:%ld fork ret:%d addr:%ld val:%d\n", getpid(), getppid(), pid, &a, a);
    } else if (pid > 0) {
        wpid = wait(&stat);
        //printf("Child exit PID:%d\n", wpid);
        // 親プロセスが実行する
        a++;
        printf("[Parent] PID:%ld PPID:%ld fork ret:%d addr:%ld val:%d\n", getpid(), getppid(), pid, &a, a);
    } else {
        printf("[Error] PID:%ld PPID:%ld fork ret:%d\n", getpid(), getppid(), pid);
    }
    // どちらも実行する
    printf("PID:%ld PPID:%ld fork ret:%d addr:%ld val:%d\n", getpid(), getppid(), pid, &a, a);

    return 0;
}
