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
        printf("Child: executing ls using execvp()\n");

        char *args[] = { "ls", "-l", "-a", NULL };

        execvp("ls", args);

        // Runs only if execvp fails
        perror("execvp failed");
        return 1;
    }

    // Parent process
    printf("Parent: child PID = %d\n", pid);
    printf("Parent: waiting for child...\n");

    wait(NULL);

    printf("Parent: child completed.\n");
    return 0;
}

