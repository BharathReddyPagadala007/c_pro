In Linux, process creation is primarily achieved using the `fork()` system call. A **process** is an instance of a running program, and the kernel manages processes using structures like `task_struct`.

### **1. Process Creation Using `fork()`**
- The `fork()` system call is used to create a new process by duplicating the calling (parent) process.
- After a `fork()`, two processes exist: 
  - **Parent Process**: The original process.
  - **Child Process**: A copy of the parent process.
- Both processes execute the next instruction after the `fork()` call.
- The return value of `fork()` helps differentiate:
  - **0** → Returned to the child process.
  - **Positive PID** → Returned to the parent with the Process ID (PID) of the child.
  - **-1** → Returned in case of failure.

#### Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
```

---

### **2. Address Space**
- The child process receives a duplicate of the parent's address space, including:
  - Code
  - Data
  - Heap
  - Stack
- However, Linux uses **Copy-on-Write (COW)** for memory optimization. Actual memory is only copied when a process writes to a page.

---

### **3. Process Initialization Using `exec()`**
- The `exec()` family of functions replaces the current process with a new program.
- After a successful `exec()` call, the previous process image is replaced.
- Example functions include:
  - `execl()`
  - `execvp()`
  - `execve()`
- Typically, `exec()` is used after a `fork()` to run a different program in the child process.

#### Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/ls", "ls", NULL); // Replaces the child process with the "ls" command
        perror("execl failed");
    } else {
        printf("Parent Process: PID = %d\n", getpid());
    }
    return 0;
}
```

---

### **4. Process Termination**
- Processes can terminate using:
  - `exit()` → Normal termination
  - `_exit()` → Immediate exit without cleanup
- The **parent process** can wait for its child's termination using `wait()` or `waitpid()`.

#### Example:
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        sleep(2);  // Simulate some work
    } else {
        wait(NULL);  // Wait for child to finish
        printf("Parent Process: Child has exited\n");
    }

    return 0;
}
```

---

### **Summary of Process Creation in Linux**
1. **fork()** → Creates a child process.
2. **exec()** → Replaces process memory with a new program.
3. **exit()** → Terminates the process.
4. **wait()** → Parent waits for child completion.

---

