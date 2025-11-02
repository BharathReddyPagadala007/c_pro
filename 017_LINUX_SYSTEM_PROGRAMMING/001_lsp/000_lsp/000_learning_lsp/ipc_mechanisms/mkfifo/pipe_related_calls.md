There are several system calls and related functions that interact with or are commonly used alongside `mkfifo()` to manage FIFO special files in Unix-like operating systems. Below is an overview of the most relevant ones:

### 1. **`mkfifo()`**
   - **Purpose**: Creates a named FIFO (First In, First Out) special file, also known as a named pipe.
   - **Prototype**:
     ```c
     int mkfifo(const char *pathname, mode_t mode);
     ```
   - **Behavior**: Creates a FIFO at the specified `pathname` with the given `mode` (permissions).

---

### 2. **`open()`**
   - **Purpose**: Opens a file (including FIFO) for reading, writing, or both. It is the system call used to open a FIFO file for communication.
   - **Prototype**:
     ```c
     int open(const char *pathname, int flags, mode_t mode);
     ```
   - **Usage with FIFO**:
     - **Reader**: Open the FIFO with `O_RDONLY` to read from it.
     - **Writer**: Open the FIFO with `O_WRONLY` to write to it.
   - **Blocking Behavior**: When a FIFO is opened for reading, it blocks until another process opens it for writing, and vice versa.

---

### 3. **`read()`**
   - **Purpose**: Reads data from a file descriptor, such as a FIFO.
   - **Prototype**:
     ```c
     ssize_t read(int fd, void *buf, size_t count);
     ```
   - **Usage with FIFO**: Used by the reader process to read data from the FIFO. It blocks if no data is available.

---

### 4. **`write()`**
   - **Purpose**: Writes data to a file descriptor, such as a FIFO.
   - **Prototype**:
     ```c
     ssize_t write(int fd, const void *buf, size_t count);
     ```
   - **Usage with FIFO**: Used by the writer process to write data to the FIFO. It blocks if no reader has opened the FIFO.

---

### 5. **`unlink()`**
   - **Purpose**: Deletes a file or a FIFO special file.
   - **Prototype**:
     ```c
     int unlink(const char *pathname);
     ```
   - **Usage with FIFO**: Deletes a named FIFO file from the filesystem, once it is no longer needed. After deletion, the FIFO is no longer accessible.

---

### 6. **`stat()`**
   - **Purpose**: Retrieves information about a file, such as its type, size, permissions, etc.
   - **Prototype**:
     ```c
     int stat(const char *pathname, struct stat *statbuf);
     ```
   - **Usage with FIFO**: The `stat()` function can be used to check the properties of a FIFO file (e.g., whether it's a regular file or FIFO). The `st_mode` field of the `stat` structure will include `S_IFIFO` for FIFO files.

---

### 7. **`fstat()`**
   - **Purpose**: Retrieves information about a file, using the file descriptor rather than the file name.
   - **Prototype**:
     ```c
     int fstat(int fd, struct stat *statbuf);
     ```
   - **Usage with FIFO**: Similar to `stat()`, but it works with an already open file descriptor (e.g., a FIFO file descriptor).

---

### 8. **`mknod()`**
   - **Purpose**: Creates a filesystem node (such as a regular file, device file, or FIFO). 
   - **Prototype**:
     ```c
     int mknod(const char *pathname, mode_t mode, dev_t dev);
     ```
   - **Usage with FIFO**: Can be used to create a FIFO file manually by passing `S_IFIFO` in the mode argument.
     - Example:
       ```c
       mknod("myfifo", S_IFIFO | 0666, 0);
       ```

---

### 9. **`open()` with `O_NONBLOCK`**
   - **Purpose**: Opens a file in non-blocking mode.
   - **Prototype**:
     ```c
     int open(const char *pathname, int flags, mode_t mode);
     ```
   - **Usage with FIFO**: When opening a FIFO, the `O_NONBLOCK` flag can be used to prevent blocking behavior. If no process has opened the FIFO for the corresponding read/write operation, the process will return immediately with an error (`EAGAIN` or `EWOULDBLOCK`), instead of blocking.
     ```c
     int fd = open("/tmp/myfifo", O_WRONLY | O_NONBLOCK);
     ```

---

### 10. **`fcntl()`**
   - **Purpose**: Manipulates file descriptors, including setting various options.
   - **Prototype**:
     ```c
     int fcntl(int fd, int cmd, ...);
     ```
   - **Usage with FIFO**: Can be used to modify the behavior of the FIFO file descriptor, such as setting it to non-blocking mode using `fcntl()` in conjunction with `O_NONBLOCK`.

---

### 11. **`pipe()`**
   - **Purpose**: Creates an anonymous pipe (not a named FIFO). It is often used for inter-process communication within the same process group.
   - **Prototype**:
     ```c
     int pipe(int pipefd[2]);
     ```
   - **Usage**: While `pipe()` is used for anonymous pipes, it’s related because both FIFO and anonymous pipes are mechanisms for IPC, but `mkfifo()` creates a named pipe that persists in the filesystem.

---

### 12. **`select()`**
   - **Purpose**: Monitors multiple file descriptors for events like readability or writability.
   - **Prototype**:
     ```c
     int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
     ```
   - **Usage with FIFO**: `select()` can be used to check whether a FIFO is ready for reading or writing, thus avoiding blocking. For example, you can check if data is available to read before attempting to read from a FIFO.

---

### Summary
Here’s a quick summary of how these system calls interact with `mkfifo()`:

- `mkfifo()` creates a named pipe (FIFO).
- `open()` is used by processes to open the FIFO for reading or writing.
- `read()` and `write()` are used to transfer data between processes through the FIFO.
- `unlink()` removes the FIFO file when it’s no longer needed.
- `stat()` or `fstat()` can be used to check the type and properties of the FIFO file.
- `fcntl()` and `O_NONBLOCK` allow for non-blocking FIFO operations.
- `mknod()` can be used to manually create a FIFO, although `mkfifo()` is more commonly used.


