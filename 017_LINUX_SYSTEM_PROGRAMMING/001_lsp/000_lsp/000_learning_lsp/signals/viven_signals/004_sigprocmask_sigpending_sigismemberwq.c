#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// ---- Custom Handler for SIGTERM ----
void term_handler(int signum) {
    printf("SIGTERM received and handled! (signum=%d)\n", signum);
}

int main() {
    sigset_t block_set, pending_set;
    struct sigaction sa;

    // -------------------------------
    // Step 1: Block SIGTERM
    // -------------------------------
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGTERM);
    sigprocmask(SIG_BLOCK, &block_set, NULL);

    printf("SIGTERM blocked. PID = %d\n", getpid());
    printf("Send SIGTERM now: kill -TERM %d\n", getpid());
    sleep(25);

    // -------------------------------
    // Step 2: Check pending signals
    // -------------------------------
    sigpending(&pending_set);

    if (sigismember(&pending_set, SIGTERM))
        printf("SIGTERM is pending.\n");
    else
        printf("SIGTERM not pending.\n");

    // -------------------------------
    // Step 3: Install SIGTERM handler
    // -------------------------------
    sa.sa_handler = term_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGTERM, &sa, NULL);

    // -------------------------------
    // Step 4: Unblock SIGTERM
    // -------------------------------
    sigprocmask(SIG_UNBLOCK, &block_set, NULL);
    printf("SIGTERM unblocked. Pending SIGTERM (if any) will now fire.\n");

    // Keep alive to demonstrate handler
    while (1) {
        printf("Working...\n");
        sleep(3);
    }

    return 0;
}

