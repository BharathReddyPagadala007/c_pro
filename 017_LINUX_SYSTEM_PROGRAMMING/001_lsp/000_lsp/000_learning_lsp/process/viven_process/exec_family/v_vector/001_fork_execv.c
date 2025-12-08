#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child: executing ls using execv()\n");

        char *args[] = { "ls", "-l", "-a", NULL };

        execv("/bin/ls", args);

        // Only executes if execv fails
        perror("execv failed");
        return 1;
    }

    // Parent process
    printf("Parent: child PID = %d\n", pid);
    printf("Parent: waiting for child...\n");

    wait(NULL);

    printf("Parent: child completed.\n");
    return 0;
}

