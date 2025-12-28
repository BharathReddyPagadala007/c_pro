#include <pthread.h>
#include <stdio.h>
#include <unistd.h>    // for sleep()

/* Parameters to print_function. */
struct char_print_parms {
    char character;   /* The character to print. */
    int count;        /* The number of times to print it. */
};

/* Thread function: prints a character 'count' times with small delays */
void* char_print(void* parameters)
{
    struct char_print_parms* p = (struct char_print_parms*) parameters;
    int i;

    for (i = 0; i < p->count; ++i) {
        fputc(p->character, stderr);   // We use stderr so it's unbuffered in most cases
        fflush(stderr);
        // Small delay so you can actually see interleaving
        // 10 seconds total spread over 'count' prints
        sleep(10 / p->count);
    }
    return NULL;
}

int main()
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_parms thread1_args;
    struct char_print_parms thread2_args;

    printf("Printing ... ");
    fflush(stdout);   // Critical! Without this, "Printing ... " may appear AFTER the x's and o's!

    /* TODO 1: Create a new thread to print 3 ’x’s */
    thread1_args.character = 'x';
    thread1_args.count = 3;
    if (pthread_create(&thread1_id, NULL, char_print, &thread1_args) != 0) {
        perror("pthread_create thread1");
        return 1;
    }

    /* TODO 2: Create a new thread to print 10 ’o’s */
    thread2_args.character = 'o';
    thread2_args.count = 10;
    if (pthread_create(&thread2_id, NULL, char_print, &thread2_args) != 0) {
        perror("pthread_create thread2");
        return 1;
    }

    /* TODO 3 & 4: Wait for both threads to finish */
    pthread_join(thread1_id, NULL);   // Wait for x-thread
    pthread_join(thread2_id, NULL);   // Wait for o-thread

    printf("\ndone\n");
    return 0;
}
