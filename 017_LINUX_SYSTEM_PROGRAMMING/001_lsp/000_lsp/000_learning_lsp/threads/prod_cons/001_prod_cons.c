#include <pthread.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 3  // The number of shelves in the counter

// Shared buffer and related variables
int buffer[BUFFER_SIZE];
int count = 0;   // Number of cakes in the buffer
int in = 0;      // Producer index
int out = 0;     // Consumer index

// Mutex and condition variables
pthread_mutex_t mutex;
pthread_cond_t cond_produce;
pthread_cond_t cond_consume;

// Producer function (baker)
void* producer(void* arg) {
    for (int i = 1; i <= 6; i++) {  // Simulate producing 6 cakes
        // Real work: Generate a unique cake ID or perform a calculation
        int cake = i * i;  // Example: producing a cake with a square number as its ID
        printf("Baker: Baking Cake #%d (ID: %d)\n", i, cake);

        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            // Wait if the buffer is full
            printf("Baker: Buffer is full, waiting...\n");
            pthread_cond_wait(&cond_produce, &mutex);
        }

        // Produce a cake and place it on the counter
        buffer[in] = cake;
        in = (in + 1) % BUFFER_SIZE;
        count++;

        pthread_cond_signal(&cond_consume);  // Signal consumer that there is a cake
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Consumer function (customer)
void* consumer(void* arg) {
    for (int i = 1; i <= 6; i++) {  // Simulate consuming 6 cakes
        pthread_mutex_lock(&mutex);

        while (count == 0) {
            // Wait if the buffer is empty
            printf("Customer: Buffer is empty, waiting...\n");
            pthread_cond_wait(&cond_consume, &mutex);
        }

        // Consume a cake from the counter
        int cake = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;

        pthread_cond_signal(&cond_produce);  // Signal producer that there is space in the buffer
        pthread_mutex_unlock(&mutex);

        // Real work: process the cake (e.g., calculate the square root of the cake ID)
        printf("Customer: Consumed Cake with ID: %d (Processed value: %.2f)\n", cake, sqrt(cake));
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_produce, NULL);
    pthread_cond_init(&cond_consume, NULL);

    // Create producer (baker) and consumer (customer) threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_produce);
    pthread_cond_destroy(&cond_consume);

    return 0;
}

