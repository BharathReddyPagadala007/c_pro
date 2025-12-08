
PIPE VS FIFO
---

### **Pipes vs. FIFOs**
- **Pipes** and **FIFOs (named pipes)** are similar in functionality; both provide a unidirectional communication channel for data.
- **Difference**:  
  - **Pipes** are created using `pipe(2)` and exist only while the processes are running. They are anonymous and exist solely in memory.
  - **FIFOs** are created using `mkfifo(3)` or `mknod(2)` and exist as named files in the filesystem. They persist even after the processes terminate.

### **I/O Semantics**
- Once a pipe or FIFO is created and opened, **the I/O operations (read/write)** are identical for both.

#### **Blocking Behavior**
- **Reading from an empty pipe**:
  - The `read(2)` system call will block (wait) until data becomes available.
- **Writing to a full pipe**:
  - The `write(2)` system call will block (wait) until space is freed in the pipe (i.e., sufficient data is read by the other end).

#### **Non-blocking I/O**
- Non-blocking behavior can be enabled using the `fcntl(2)` system call:
  - Use the `F_SETFL` operation to set the `O_NONBLOCK` flag for the pipe or FIFO.
  - In non-blocking mode:
    - A read on an empty pipe will return immediately with `-1` and `errno` set to `EAGAIN` or `EWOULDBLOCK`.
    - A write to a full pipe will also return `-1` with the same `errno` values.

#### **Byte Stream Communication**
- Pipes provide a **byte stream**, meaning they treat the data as a continuous sequence of bytes.  
  - **No message boundaries**: If multiple writers write data to the pipe, the data may interleave unless explicitly synchronized by the application.

---

### **Special Conditions**
- **End-of-file (EOF):**
  - If all file descriptors associated with the **write end** of a pipe are closed:
    - A `read(2)` on the pipe will return `0`, indicating EOF.
  - If all file descriptors associated with the **read end** of a pipe are closed:
    - A `write(2)` will cause:
      - A `SIGPIPE` signal to be sent to the process attempting the write.
      - If `SIGPIPE` is ignored, the `write(2)` will fail with an `EPIPE` error.

#### **Duplication of File Descriptors**
- When using `fork(2)` with pipes:
  - The parent and child processes inherit duplicate file descriptors for the pipe ends.
  - **Best Practice**: Use `close(2)` to close unnecessary descriptors to:
    - Avoid resource leaks.
    - Ensure EOF and SIGPIPE/EPIPE are delivered correctly when a pipe end is no longer needed.

---

### **Limitations**
- **No `lseek(2)`**:
  - Seeking is not supported on pipes because they are streams without a defined start, end, or random-access capability.

---

### Summary
- Pipes and FIFOs are useful for interprocess communication, but they operate as blocking byte streams unless explicitly configured for non-blocking mode.  
- Proper management of file descriptors ensures clean EOF and signal behavior.
- They are limited to sequential access, and their behavior must be carefully handled to avoid deadlocks or unexpected blocking.
