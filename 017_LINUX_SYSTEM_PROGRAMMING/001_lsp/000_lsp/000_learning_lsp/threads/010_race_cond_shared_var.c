#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS 100000

int counter = 0; // Shared resource

void* increment_counter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        counter++; // Critical section without synchronization
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final Counter Value: %d (Expected: %d)\n", counter, 2 * NUM_ITERATIONS);
    return 0;
}

