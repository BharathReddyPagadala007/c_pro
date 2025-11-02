#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void* print_message(void* arg) {
    int thread_id = *((int*)arg); // Access the thread ID from the array
    printf("Hello from Thread %d!\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS]; // Array to hold thread IDs

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i + 1; // Assign thread ID
        if (pthread_create(&threads[i], NULL, print_message, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

