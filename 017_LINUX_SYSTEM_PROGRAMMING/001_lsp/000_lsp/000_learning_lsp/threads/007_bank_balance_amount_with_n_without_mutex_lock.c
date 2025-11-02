#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_OPERATIONS 100000

int balance = 10000; // Shared resource
pthread_mutex_t lock; // Mutex lock

// Deposit function
void deposit(int amount) {
    balance += amount;
}

// Withdraw function
void withdraw(int amount) {
    if (balance >= amount) {
        balance -= amount;
    }
}

// Thread function without mutex
void *transaction_no_lock(void *arg) {
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        deposit(10);
        withdraw(10);
    }
    return NULL;
}

// Thread function with mutex
void *transaction_with_lock(void *arg) {
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        pthread_mutex_lock(&lock); // Lock the critical section
        deposit(10);
        withdraw(10);
        pthread_mutex_unlock(&lock); // Unlock the critical section
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int use_mutex;

    printf("Enter 1 to use mutex or 0 to not use mutex: ");
    scanf("%d", &use_mutex);

    if (use_mutex) {
        pthread_mutex_init(&lock, NULL); // Initialize mutex
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (use_mutex) {
            pthread_create(&threads[i], NULL, transaction_with_lock, NULL);
        } else {
            pthread_create(&threads[i], NULL, transaction_no_lock, NULL);
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (use_mutex) {
        pthread_mutex_destroy(&lock); // Destroy mutex
    }

    printf("Final balance: %d\n", balance);
    return 0;
}

