#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void segv_handler(int signum)
{
    printf("Caught SIGSEGV! signum = %d\n", signum);
    exit(1);   // exit instead of crashing
}

int main()
{
    struct sigaction act;

    act.sa_handler = segv_handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);

    sigaction(SIGSEGV, &act, NULL);

    printf("Triggering segmentation fault...\n");

    int *ptr = NULL;
    *ptr = 10;    // deliberate segmentation fault

    return 0;
}

