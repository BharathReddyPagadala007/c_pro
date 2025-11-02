#include <stdio.h>
#include <pthread.h>

// Shared variable to store the result
int shared_result = 1;

// Function to compute factorial for a given range
void* compute_partial_factorial(void* arg) {
    int num = *(int*)arg;

    for (int i = 1; i <= num; i++) {
        // Print the current thread and the current value of shared_result
        printf("Thread: %ld, shared_result before: %d, multiplying by: %d\n", pthread_self(), shared_result, i);
        
        shared_result *= i;

        // Print after multiplication
        printf("Thread: %ld, shared_result after: %d\n", pthread_self(), shared_result);
    }
    return NULL;
}

int main() {
    int n = 5; // Calculate 5!

    pthread_t thread1, thread2;

    // Create two threads that will both try to compute the entire factorial
    pthread_create(&thread1, NULL, compute_partial_factorial, &n);
    pthread_create(&thread2, NULL, compute_partial_factorial, &n);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the result (likely incorrect due to the race condition)
    printf("Factorial of %d with race condition is: %d\n", n, shared_result);

    return 0;
}

