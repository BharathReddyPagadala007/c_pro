#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before execlp()\n");

    // execlp searches "ls" in PATH
    execlp("ls", "ls", "-l", "-a", NULL);

    // Only runs if execlp fails
    perror("execlp failed");
    return 1;
}

