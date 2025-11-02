#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd1 = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd1 == -1) {
        perror("open");
        return 1;
    }
    int fd2 = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    printf("File Descriptor: %d\n", fd1);
    printf("File Descriptor: %d\n", fd2);

    close(fd1);
    close(fd2);
    return 0;
}

