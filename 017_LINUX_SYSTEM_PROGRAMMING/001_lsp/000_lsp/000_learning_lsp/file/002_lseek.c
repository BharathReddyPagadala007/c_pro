#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd = open("lseektest.txt", O_CREAT | O_RDWR, 0666);
    if (fd < 0) {
        printf("Open failed\n");
        return 1; // Exit if file open fails
    }

    // Write some initial data to the file
    write(fd, "hellotytyutyt", 13);  // Write 13 bytes

    // Reset file offset to the beginning
    lseek(fd, 0, SEEK_SET);

    char buffer[15];
    int bytes_read = read(fd, buffer, 13); // Read up to 13 bytes
    if (bytes_read < 0) {
        printf("Read failed\n");
        close(fd);
        return 1;
    }

    // Null-terminate the buffer to make it a proper string
    buffer[bytes_read] = '\0';
    printf("The buffer = ==> %s\n", buffer);

    // Move the offset to the 5th byte
    lseek(fd, 5, SEEK_SET);

    // Check the current file size
    off_t filesize = lseek(fd, 0, SEEK_END);
    printf("The filesize = %ld\n", filesize);

    close(fd);
    return 0;
}
////////////////////////////////////////////////
//prev content in file is remained 
//inorder to clear exiting content use
//  O_TRUNC 
//  flag
//  ///////////////////////////////////////////

