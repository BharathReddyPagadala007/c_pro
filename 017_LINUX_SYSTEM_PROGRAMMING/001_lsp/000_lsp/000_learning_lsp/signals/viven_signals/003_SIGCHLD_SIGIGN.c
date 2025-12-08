#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/* Function to set SIGCHLD to be ignored */
int ignore_sigchld(void) {
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;           // No special flags needed
    sa.sa_handler = SIG_IGN;   // Ignore the signal

    	sigaction(SIGCHLD, &sa, NULL);

    printf("SIGCHLD is now set to be ignored.\n");
    return 0;
}

/* Function to restore default SIGCHLD behavior (optional) */
int restore_sigchld(void) {
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = SIG_DFL;   // Restore default behavior

   	 sigaction(SIGCHLD, &sa, NULL);

    printf("SIGCHLD behavior restored to default.\n");
    return 0;
}

int main(void) {
    pid_t child_pid;

    /* Temporarily ignore SIGCHLD */
    	ignore_sigchld();

    printf("Parent PID: %d\n", getpid());

    /* Fork a child process */
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        /* Child process */
        printf("Child PID: %d starting...\n", getpid());
        sleep(2);
        printf("Child PID: %d exiting.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */
        printf("Parent: spawned child with PID %d\n", child_pid);

        /* Parent continues without waiting - child becomes zombie? NO! */
        /* Because SIGCHLD is ignored, the system automatically reaps the child */
        printf("Parent: doing some work while child runs...\n");
        sleep(5);

        /* At this point, the child has already been automatically cleaned up */
        printf("Parent: child should have been automatically reaped (no zombie).\n");

        /* Try to wait - should return error (no children) */
        if (wait(NULL) == -1) {
            if (errno == ECHILD) {
                printf("Confirmed: no child processes exist (was auto-reaped).\n");
            } else {
                perror("wait");
            }
        }
    }

    /* Optionally restore default behavior before exiting */
    restore_sigchld();

    printf("Program terminated normally.\n");
    return 0;
}
