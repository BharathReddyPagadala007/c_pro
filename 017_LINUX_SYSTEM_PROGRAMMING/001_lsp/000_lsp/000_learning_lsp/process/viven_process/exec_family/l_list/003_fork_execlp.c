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
        printf("Child: executing ls via execlp()\n");
        execlp("ls", "ls", "-l", "-a", NULL);

        // This runs ONLY if execlp fails
        perror("execlp failed");
        return 1;
    }

    // Parent process
    printf("Parent: created child with PID = %d\n", pid);
    printf("Parent: waiting for child to finish...\n");

    wait(NULL);

    printf("Parent: child finished.\n");
    return 0;
}

