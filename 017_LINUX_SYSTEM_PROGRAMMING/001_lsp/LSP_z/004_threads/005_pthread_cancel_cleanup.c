#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>     // for sleep()

/* Allocate a temporary buffer */
void *allocate_buffer(size_t size)
{
    printf("Resource Allocated\n");
    return malloc(size);
}

/* Deallocate a temporary buffer - this will be our cleanup handler */
void deallocate_buffer(void *buffer)
{
    free(buffer);
    printf("\nResource Freed (via cleanup handler)\n");
}

void *do_some_work(void *arg)
{
    /* Allocate a temporary buffer */
    void *temp_buffer = allocate_buffer(1024);

    /* 
     * TODO 1: Register cleanup handler
     * This ensures deallocate_buffer() is called automatically if:
     *   - pthread_cancel() is called
     *   - pthread_exit() is called
     *   - the thread returns from this function with an exception (C++)
     */
    pthread_cleanup_push(deallocate_buffer, temp_buffer);

    printf("\nThread working: \n");
    
    /* Simulate work - each sleep() is a cancellation point */
    int i;
    for (i = 0; i < 10; i++) {
        fputc('c', stderr);
        fflush(stderr);
        sleep(1);
    }

    /* 
     * TODO 2: Unregister the cleanup handler (with execute = 0)
     * Because we reached here normally, we don't want the cleanup to run.
     */
    pthread_cleanup_pop(0);

    printf("\nThread finished normally - buffer still valid\n");
    free(temp_buffer);  // manually free since we didn't let cleanup do it
    printf("\nResource Freed manually\n");

    return NULL;
}

int main()
{
    pthread_t thread_id;
    void *status;

    printf("\nMain: creating thread\n");

    if (pthread_create(&thread_id, NULL, do_some_work, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    sleep(3);  // Let thread print "ccc" three times

    printf("\nMain: cancelling thread...\n");
    pthread_cancel(thread_id);

    pthread_join(thread_id, &status);

    if (status == PTHREAD_CANCELED) {
        printf("\nThread was cancelled - cleanup handler WAS executed!\n");
    } else {
        printf("Thread terminated normally\n");
    }

    printf("Main: done\n");
    return 0;
}
