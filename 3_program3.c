#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int a[101];
int b[101];

static void setData() {
    for (int i = 1; i <= 101; i++) {
        a[i] = i;
        b[i] = i * 1000;
    }
}

void *threadFuncA(void *arg) {
    for (int i1 = 2; i1 <= 51; i1++) {
        a[i1] = a[i1 - 1] + b[i1];
    }
    return NULL;
}

void *threadFuncB(void *arg) {
    for (int i2 = 52; i2 <= 101; i2++) {
        a[i2] = a[i2 - 1] + b[i2];
    }
    return NULL;
}

int main(void) {
    pthread_t threadA;
    pthread_t threadB;

    setData();

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

    for (int i = 1; i <= 100; i++) {
        printf("a[%03d]:%07d\n", i, a[i]);
    }

    return 0;
}
