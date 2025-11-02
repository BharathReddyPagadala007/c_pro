#include <fcntl.h>  // For open
#include <unistd.h> // For close, write, dup
#include <stdio.h>  // For printf

int main() {
    // Open the file example.txt with write-only permissions
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Original FD: %d\n", fd);

    // Duplicate the file descriptor
    int fd_dup = dup(fd);
    if (fd_dup == -1) {
        perror("Error duplicating file descriptor");
        return 1;
    }

    printf("Duplicated FD: %d\n", fd_dup);

    // Write using both descriptors
    write(fd, "Writing with original FD\n", 26);
lseek(fd_dup, 0, SEEK_SET); // Reset offset using duplicated FD
write(fd_dup, "Overwriting with duplicated FD\n", 32);


    sleep(300);

    // Close both file descriptors
    close(fd);
    close(fd_dup);

    return 0;
}

