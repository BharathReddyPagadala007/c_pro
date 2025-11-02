#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo_path = "/tmp/my_fifo";

    // Create a FIFO (named pipe)
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO created at %s\n", fifo_path);

    // Open the FIFO for writing
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write data to the FIFO
    const char *msg = "Hello, FIFO!";
    write(fd, msg, sizeof(msg));
    printf("Message sent: %s\n", msg);

    // Close the FIFO
    close(fd);

    // Cleanup (optional: remove the FIFO)
    unlink(fifo_path);

    return 0;
}

