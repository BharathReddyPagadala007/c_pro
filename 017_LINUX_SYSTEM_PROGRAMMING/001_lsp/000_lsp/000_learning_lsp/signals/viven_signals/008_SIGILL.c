#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void sigill_handler(int s) {
    printf("Caught SIGILL via raise()! signum = %d\n", s);
    exit(1);
}

int main() {
    signal(SIGILL, sigill_handler);
    printf("Raising SIGILL...\n");
    raise(SIGILL);  // reliably triggers the handler on WSL
    return 0;
}

