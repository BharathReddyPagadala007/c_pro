#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigterm_handler(int signum)
{
    printf("Custom SIGTERM handler invoked! signum = %d\n", signum);
}

int main()
{
    struct sigaction act;

    act.sa_handler = sigterm_handler;
    act.sa_flags   = 0;
    sigemptyset(&act.sa_mask);

    sigaction(SIGTERM, &act, NULL);

    printf("PID = %d. Send SIGTERM using: kill -TERM %d\n", getpid(), getpid());

    while (1) {
        pause();   // sleep until a signal arrives
    }

    return 0;
}

