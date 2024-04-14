#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

static void outLog(char *fname) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("FUNC:%s TID:%ld", fname, gettid());
    printf(" Date:%ld(usec) %s", tv.tv_usec, asctime(localtime(&tv.tv_sec)));
}

void *threadFuncA(void *arg) {
    for (int i = 0; i < 2; i++) {
        usleep(100);
        outLog(__func__);
    }
    return NULL;
}

void *threadFuncB(void *arg) {
    for (int i = 0; i < 2; i++) {
        usleep(150);
        outLog(__func__);
    }
    return NULL;
}

int main(void) {
    pthread_t threadA;
    pthread_t threadB;

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
