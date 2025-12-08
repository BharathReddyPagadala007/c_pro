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
        printf("Child: executing ls using execve() with custom environment\n");

        char *args[] = { "ls", "-l", "-a", NULL };
        char *env[] = {
            "PATH=/bin:/usr/bin",
            "MYVAR=HELLO_CHILD",
            NULL
        };

        execve("/bin/ls", args, env);

        // Only runs if execve fails
        perror("execve failed");
        return 1;
    }

    // Parent process
    printf("Parent: child PID = %d\n", pid);
    printf("Parent: waiting for child to finish...\n");

    wait(NULL);

    printf("Parent: child finished.\n");

    return 0;
}

