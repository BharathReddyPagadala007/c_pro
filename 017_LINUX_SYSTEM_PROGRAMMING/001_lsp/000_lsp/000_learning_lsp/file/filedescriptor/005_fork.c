#include <fcntl.h>  // For open
#include <unistd.h> // For close, fork, write
#include <stdio.h>  // For printf
#include <sys/types.h> // For pid_t

int main() {
    // Open the file example.txt with write-only permissions
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File Descriptor in Parent: %d\n", fd);

    // Fork the process
    pid_t pid = fork();

    if (pid == -1) {
        perror("Error forking");
        close(fd);
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("In Child Process\n");
        write(fd, "Child writes here\n", 18);
    } else {
        // Parent process
        printf("In Parent Process\n");
        write(fd, "Parent writes here\n", 19);
    }

    sleep(300);
    // Close the file descriptor in both processes
    close(fd);
    return 0;
}

