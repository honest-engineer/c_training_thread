#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int a[100];
int b[100];
int c[100];

static void setData() {
    for (int i = 1; i <= 100; i++) {
        b[i] = i;
        c[i] = i * 1000;
    }
}

void *threadFuncA(void *arg) {
    for (int i1 = 1; i1 <= 50; i1++) {
        a[i1] = b[i1] + c[i1];
    }
    return NULL;
}

void *threadFuncB(void *arg) {
    for (int i2 = 51; i2 <= 100; i2++) {
        a[i2] = b[i2] + c[i2];
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
        printf("a[%03d]:%06d\n", i, a[i]);
    }

    return 0;
}
