#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execvp()\n");

    char *args[] = { "ls", "-l", "-a", NULL };

    // execvp searches "ls" in PATH
    execvp("ls", args);

    // Only runs if execvp() fails
    perror("execvp failed");
    return 1;
}

