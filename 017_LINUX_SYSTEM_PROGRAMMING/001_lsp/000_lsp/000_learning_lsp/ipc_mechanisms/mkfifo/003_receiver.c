#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/my_fifo"

int main() {
    char buffer[100];
    int fd;

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        // If FIFO already exists, continue
    }

    // Open FIFO for reading
    printf("Receiver: Waiting for Sender to write to FIFO...\n");
    fd = open(FIFO_PATH, O_RDONLY); // Blocks until a writer opens the FIFO
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Read the message from the FIFO
    printf("Receiver: Waiting for message...\n");
    read(fd, buffer, sizeof(buffer)); // Blocks until data is written
    printf("Receiver: Received message: %s\n", buffer);

    close(fd); // Close the FIFO
    return 0;
}

