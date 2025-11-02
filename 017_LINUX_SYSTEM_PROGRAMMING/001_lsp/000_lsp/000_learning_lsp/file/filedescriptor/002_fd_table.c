#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    printf("File Descriptor: %d\n", fd);
    sleep(30); // Pause the program to inspect

    close(fd);
    return 0;
}

