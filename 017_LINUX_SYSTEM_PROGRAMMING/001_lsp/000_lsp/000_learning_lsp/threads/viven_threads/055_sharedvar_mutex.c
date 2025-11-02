#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS 100000000

int shared_variable = 0; // Shared resource
pthread_mutex_t mutex;   // Mutex lock

// Function to be executed by each thread
void* increment_variable(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        // Lock the mutex before accessing the shared variable
        pthread_mutex_lock(&mutex);

        shared_variable++; // Increment the shared variable

        // Unlock the mutex after accessing the shared variable
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, increment_variable, NULL);
    pthread_create(&thread2, NULL, increment_variable, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the final value of the shared variable
    printf("Final value of shared_variable: %d\n", shared_variable);

    return 0;
}

