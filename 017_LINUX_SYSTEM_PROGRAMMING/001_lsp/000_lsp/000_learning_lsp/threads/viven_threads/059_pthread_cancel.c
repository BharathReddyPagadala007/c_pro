#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* thread_function(void* arg) {
    while (1) {
        printf("Thread is running...\n");
        sleep(1);  // Simulating work
    }
    return NULL;
}

int main() {
    pthread_t thread;
    
    // Create the thread
pthread_create(&thread, NULL, thread_function, NULL); 

    // Allow the thread to run for a few seconds
    sleep(20);

    // Cancel the thread
    printf("Main thread: Cancelling the thread\n");
    pthread_cancel(thread); 

    // Wait for the thread to terminate
    pthread_join(thread, NULL); 

    printf("Main thread: Thread cancelled and joined\n");

    return 0;
}

