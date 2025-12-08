#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execle()\n");

    // Custom environment for the new process
    char *myenv[] = {
        "MYVAR=HELLO_WORLD",
        "PATH=/bin:/usr/bin",
        NULL
    };

    execle("/usr/bin/env", "env", NULL, myenv);

    // Runs only if execle fails
    perror("execle failed");
    return 1;
}

