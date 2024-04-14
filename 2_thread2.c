#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int a = 0;

static void outLog(char *fname) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("FUNC:%s TID:%ld addr:%ld val:%d\n", fname, gettid(), &a, a);
}

void *threadFuncA(void *arg) {
    a++;
    outLog(__func__);
    return NULL;
}

void *threadFuncB(void *arg) {
    a++;
    outLog(__func__);
    return NULL;
}

int main(void) {
    pthread_t threadA;
    pthread_t threadB;

    a++;
    outLog(__func__);

    if(pthread_create(&threadA, NULL, threadFuncA, NULL) != 0) {
        printf("Error: Failed to create new thread.\n");
        exit(1);
    }

    if(pthread_create(&threadB, NULL, threadFuncB, NULL) != 0) {
        printf("Error: Failed to create new thread.\n");
        exit(1);
    }

    if(pthread_join(threadA, NULL) != 0) {
        printf("Error: Failed to wait for the thread termination.\n");
        exit(1);
    }

    if(pthread_join(threadB, NULL) != 0) {
        printf("Error: Failed to wait for the thread termination.\n");
        exit(1);
    }

    return 0;
}
