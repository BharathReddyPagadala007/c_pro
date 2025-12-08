#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execve()\n");

    // Arguments for the new program
    char *args[] = { "ls", "-l", "-a", NULL };

    // Environment for the new program
    char *env[] = {
        "PATH=/bin:/usr/bin",
        "MYVAR=HELLO_EXECVE",
        NULL
    };

    execve("/bin/ls", args, env);

    // Only runs if execve fails
    perror("execve failed");
    return 1;
}

