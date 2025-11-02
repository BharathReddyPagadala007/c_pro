#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;  // Reader-Writer Lock

int counter = 0;  // Shared resource

// Reader thread
void* reader(void* arg) {
    while (1) {
        pthread_rwlock_rdlock(&rwlock);  // Lock for reading

        // Read the shared resource
        printf("Reader: Counter value = %d\n", counter);

        pthread_rwlock_unlock(&rwlock);  // Unlock after reading

        sleep(1);  // Simulate other work
    }
    return NULL;
}

// Writer thread
void* writer(void* arg) {
    while (1) {
        pthread_rwlock_wrlock(&rwlock);  // Lock for writing

        // Write to the shared resource
        counter++;
        printf("Writer: Counter value updated to %d\n", counter);

        pthread_rwlock_unlock(&rwlock);  // Unlock after writing

        sleep(2);  // Simulate other work
    }
    return NULL;
}

int main() {
    pthread_t readers[5], writers[2];

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        pthread_create(&writers[i], NULL, writer, NULL);
    }

    // Wait for threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}

