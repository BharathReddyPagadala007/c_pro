#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char buf[64];
    int fd;
    ssize_t ret;

    // Create the FIFO if it doesn't exist
    if (mkfifo("fifoobj", 0666) < 0) {
        perror("Error creating FIFO object");
    }

    printf("Waiting for client to connect...\n");

    // Open the FIFO for reading
    fd = open("fifoobj", O_RDONLY);
    if (fd < 0) {
        perror("Error opening FIFO for reading");
        return 1;
    }

    printf("Client connected.\n");
    printf("Waiting for client message...\n");

    // Read data from the FIFO
    ret = read(fd, buf, sizeof(buf) - 1);
    if (ret < 0) {
        perror("Error reading from FIFO");
        close(fd);
        return 1;
    }

    buf[ret] = '\0'; // Null-terminate the received string
    printf("Message received: %s\n", buf);

    // Close the FIFO
    close(fd);
    return 0;
}

