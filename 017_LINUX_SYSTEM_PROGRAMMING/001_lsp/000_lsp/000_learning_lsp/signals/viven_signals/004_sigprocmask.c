#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t set;

    // 1. Initialize empty signal set
    sigemptyset(&set);

    // 2. Add SIGTERM to the set
    sigaddset(&set, SIGTERM);

    // 3. Block SIGTERM
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("SIGTERM is now blocked. PID = %d\n", getpid());
    printf("Send SIGTERM now (it will be blocked): kill -TERM %d\n", getpid());

    // Keep the process alive so you can test it
    while (1) {
        printf("Running...\n");
        sleep(3);
    }

    return 0;
}

////////////////////////////////
//
//  kill -l 
//  SIGTERM IS 15
//  kill -15 [pid]  ---> no effect
//  kill -9 [pid] ----> this cant b blocked or masked
