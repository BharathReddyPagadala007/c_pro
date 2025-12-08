#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execv()\n");

    // Argument list for ls
    char *args[] = { "ls", "-l", "-a", NULL };

    execv("/bin/ls", args);

    // Runs only if execv fails
    perror("execv failed");
    return 1;
}

