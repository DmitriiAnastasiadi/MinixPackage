#include <stdio.h>
#include <stdlib.h>
#include <minix/mthread.h>
#include <unistd.h>

#define NUM_THREADS 5

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;

    for (int i = 0; i < 3; i++) {
        printf("Thread %d: iteration %d\n", thread_id, i);
        mthread_yield();
        usleep(200);
    }

    mthread_exit(NULL);
    return NULL;
}

int main() {
    mthread_thread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;

        if (mthread_create(&threads[i], NULL, thread_function, 
&thread_ids[i]) != 0) {
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        mthread_join(threads[i], NULL);
    }

    printf("All threads finished.\n");
    return 0;
}
