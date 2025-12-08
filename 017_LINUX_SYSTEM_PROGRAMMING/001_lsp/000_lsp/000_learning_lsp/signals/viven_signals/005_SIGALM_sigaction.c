#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarm_handler(int signum)
{
    printf("SIGALRM received! signum = %d\n", signum);
}

int main()
{
    struct sigaction act;

    act.sa_handler = alarm_handler;
    act.sa_flags   = 0;

    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM, &act, NULL);

    printf("Setting alarm for 3 seconds...\n");
    alarm(3);

    while (1) {
        printf("Waiting...\n");
        sleep(1);
    }

    return 0;
}

