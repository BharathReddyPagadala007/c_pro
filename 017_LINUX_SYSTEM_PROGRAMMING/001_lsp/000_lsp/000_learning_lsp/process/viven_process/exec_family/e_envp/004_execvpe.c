#define _GNU_SOURCE     // Required for execvpe
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execvpe()\n");

    // Arguments for the new program
    char *args[] = { "env", NULL };

    // Custom environment
    char *env[] = {
        "MYVAR=HELLO_EXECVPE",
        "PATH=/bin:/usr/bin",
        NULL
    };

    // execvpe searches "env" in PATH and uses custom environment
    execvpe("env", args, env);

    // Only runs if execvpe fails
    perror("execvpe failed");
    return 1;
}

