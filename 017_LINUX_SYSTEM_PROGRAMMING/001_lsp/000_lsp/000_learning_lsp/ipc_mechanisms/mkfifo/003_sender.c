#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/my_fifo"

int main() {
    char message[100];
    int fd;

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        // If FIFO already exists, continue
    }

    // Take input from the user
    printf("Sender: Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    // Remove the newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Open FIFO for writing
    printf("Sender: Waiting for Receiver to open FIFO...\n");
    fd = open(FIFO_PATH, O_WRONLY); // Blocks until a reader opens the FIFO
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write the message to the FIFO
    printf("Sender: Writing to FIFO...\n");
    write(fd, message, strlen(message) + 1); // Include null terminator
    printf("Sender: Message written to FIFO.\n");

    close(fd); // Close the FIFO
    return 0;
}

