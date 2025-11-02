Communication between a server and a client using `mkfifo()` (a named pipe) involves using the FIFO as a communication channel between two processes. Here, one process acts as a **server** (usually the reader) and the other as a **client** (usually the writer). Both processes interact with the FIFO file in a synchronous manner.

### Steps to Establish Communication Between Server and Client Using `mkfifo()`

#### 1. **Create the FIFO File**
The FIFO file must first be created using the `mkfifo()` system call. This file acts as a communication channel between the two processes. It is stored on the filesystem, so both the server and client can access it.

#### 2. **Server Process: Open the FIFO for Reading**
The server process will open the FIFO for reading. If no data is available (i.e., if the client hasn’t written anything), the server will block and wait for data to be written into the FIFO.

#### 3. **Client Process: Open the FIFO for Writing**
The client process will open the FIFO for writing. If no one is ready to read (i.e., if the server hasn’t opened the FIFO for reading), the client will block and wait for the server to open the FIFO for reading.

#### 4. **Data Transfer**
Once both the server and client open the FIFO (the server for reading and the client for writing), they can communicate by writing and reading data from the FIFO.

#### 5. **Close the FIFO**
Once the communication is complete, both processes will close the FIFO using the `close()` system call.

### Example Code to Demonstrate Communication Using `mkfifo()`

#### Server Code (Reader)
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifoPath = "/tmp/myfifo";
    char buffer[128];

    // Create FIFO (server side)
    if (mkfifo(fifoPath, 0666) == -1) {
        perror("mkfifo failed");
        exit(EXIT_FAILURE);
    }

    // Open FIFO for reading
    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    // Read data from the FIFO
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';  // Null-terminate string
        printf("Server received: %s\n", buffer);
    } else {
        perror("Read failed");
    }

    // Close FIFO
    close(fd);
    return 0;
}
```

#### Client Code (Writer)
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifoPath = "/tmp/myfifo";
    const char *message = "Hello from client!";

    // Open FIFO for writing
    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    // Write data to the FIFO
    write(fd, message, sizeof(message));
    
    // Close FIFO
    close(fd);
    return 0;
}
```

### Detailed Communication Flow

1. **Create FIFO**:
   - The `mkfifo()` function is used in both the server and client code to create a named pipe (FIFO) in the filesystem at `/tmp/myfifo`.
   
2. **Server Waits for Data**:
   - The server opens the FIFO for reading (`open(fifoPath, O_RDONLY)`), which blocks the server until the client writes data to the FIFO. The server will wait for the client to open the FIFO for writing.
   
3. **Client Writes Data**:
   - The client opens the FIFO for writing (`open(fifoPath, O_WRONLY)`). Once the FIFO is opened for writing, the client can write data to the FIFO using `write()`.
   - If the server is waiting for data, the data will be transferred from the client to the server.

4. **Server Receives Data**:
   - After the client writes the data, the server can read it from the FIFO using `read()`. If the server was blocked and waiting for data, it will now receive it once the client has written.

5. **Close FIFO**:
   - Both the server and client close the FIFO once the communication is done using `close()`.

### Behavior of Blocking and Synchronization

- **Blocking**: Both the server and client will block if they try to perform operations on the FIFO and the other end isn’t ready. For example:
  - The server will block if it opens the FIFO for reading and no client has opened it for writing.
  - The client will block if it tries to open the FIFO for writing and no server has opened it for reading.
  
  This blocking behavior ensures synchronization between the processes: data is only transferred when both sides are ready.

### Error Handling
In a real-world scenario, error handling is important:
- If a process tries to write to the FIFO while the other side is not open for reading, or if the FIFO file doesn't exist, it would result in an error.
- Error handling should also include checking for failure of `mkfifo()` (if the FIFO cannot be created) and `open()`, `read()`, or `write()` system calls.

### Conclusion
Using `mkfifo()` for communication between a server and a client establishes a **synchronous communication** channel where the server waits for the client to write and the client waits for the server to read. This ensures that data is transmitted in an orderly fashion without data loss, provided the processes synchronize properly by opening the FIFO at both ends.
