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
        printf("Child: executing env with custom environment using execle()\n");

        // Custom environment for the child process
        char *myenv[] = {
            "MYVAR=HELLO_CHILD",
            "PATH=/bin:/usr/bin",
            NULL
        };

        execle("/usr/bin/env", "env", NULL, myenv);

        // Only executes if execle fails
        perror("execle failed");
        return 1;
    }

    // Parent process
    printf("Parent: child PID = %d\n", pid);
    printf("Parent: waiting for child to finish...\n");

    wait(NULL);

    printf("Parent: child finished.\n");

    return 0;
}

