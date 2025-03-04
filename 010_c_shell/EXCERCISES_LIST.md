To contribute to the `esh` UART-based shell project, you need strong C skills in **system programming**, **file handling**, **process management**, and **I/O operations**. Below are **exercises** that will help you prepare for `esh` development.

---

## **1. Implement a Mini Shell (Basic)**
### **Task**
Write a basic shell that:
- Reads user input (`getline()` or `read()`).
- Splits the command into arguments.
- Uses `fork()` and `execvp()` to execute commands.
- Waits for the command to complete using `waitpid()`.

### **Hints**
- Use `char *strtok(char *str, const char *delim)` to tokenize input.
- Use `execvp(argv[0], argv)` to execute a command.

### **Example Input/Output**
```sh
$ ls
file1.c file2.c main.c
$ echo "Hello"
Hello
$ exit
```

---

## **2. Implement `read()` and `write()` Based UART I/O**
### **Task**
Simulate reading/writing from a **UART** device using file descriptors.
- Open a pseudo-terminal (e.g., `/dev/pts/1`).
- Implement `uart_read()` and `uart_write()`.
- Use `read()` and `write()` to handle I/O.

### **Hints**
- Use `open("/dev/pts/1", O_RDWR);`
- Use `tcgetattr()` and `tcsetattr()` for UART settings.

### **Example Code**
```c
int fd = open("/dev/pts/1", O_RDWR);
write(fd, "Hello UART\n", 11);
char buffer[100];
read(fd, buffer, 100);
```

---

## **3. Implement a Command Dispatcher**
### **Task**
Write a function that takes a command string and executes the correct function.

### **Example**
```c
void cmd_ls() { printf("Executing ls\n"); }
void cmd_exit() { exit(0); }

void execute_command(char *cmd) {
    if (strcmp(cmd, "ls") == 0) cmd_ls();
    else if (strcmp(cmd, "exit") == 0) cmd_exit();
    else printf("Command not found\n");
}
```

### **Example Input/Output**
```sh
$ ls
Executing ls
$ exit
```

---

## **4. Implement a Basic `add_cmd()` Function (Like `esh`)**
### **Task**
- Implement a `struct` for shell commands.
- Implement `add_cmd()` to register commands dynamically.

### **Example**
```c
typedef void (*cmd_func)();

struct Command {
    char name[10];
    cmd_func func;
};

void add_cmd(struct Command *cmds, int *count, const char *name, cmd_func func) {
    strcpy(cmds[*count].name, name);
    cmds[*count].func = func;
    (*count)++;
}
```

---

## **5. Implement a Non-Blocking Input System (Using `select()`)**
### **Task**
- Use `select()` to check if data is available on stdin.
- This simulates **UART polling mode**.

### **Example Code**
```c
fd_set set;
struct timeval timeout;
FD_ZERO(&set);
FD_SET(STDIN_FILENO, &set);
timeout.tv_sec = 1;
timeout.tv_usec = 0;
if (select(1, &set, NULL, NULL, &timeout) > 0) {
    char buf[100];
    read(STDIN_FILENO, buf, sizeof(buf));
    printf("Received: %s\n", buf);
}
```

---

## **6. Implement `dmesg`-like Circular Buffer for Logging**
### **Task**
- Create a **ring buffer** that stores logs.
- Old logs should be overwritten when the buffer is full.

### **Example Code**
```c
#define LOG_SIZE 5
char log_buffer[LOG_SIZE][100];
int log_index = 0;

void add_log(const char *msg) {
    snprintf(log_buffer[log_index], 100, "%s", msg);
    log_index = (log_index + 1) % LOG_SIZE;
}
```

---

## **7. Implement Signal Handling (`CTRL+C`, `CTRL+Z`)**
### **Task**
- Catch `SIGINT` (`CTRL+C`) and `SIGTSTP` (`CTRL+Z`).
- Print a message instead of exiting.

### **Example Code**
```c
void sig_handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGINT, sig_handler);
    signal(SIGTSTP, sig_handler);
    while (1) sleep(1);
}
```

---

## **8. Implement `malloc()`-Free String Parsing**
### **Task**
- Parse input **without dynamic allocation** (`malloc()` is slow in embedded systems).
- Use `strtok_r()` with a fixed-size buffer.

---

## **9. Implement a UART-Style FIFO Buffer (Interrupt Mode)**
### **Task**
- Use a **fixed-size queue** to store received characters.
- Implement **enqueue()** and **dequeue()**.

### **Example**
```c
#define BUFFER_SIZE 10
char uart_buffer[BUFFER_SIZE];
int head = 0, tail = 0;

void enqueue(char c) {
    uart_buffer[head] = c;
    head = (head + 1) % BUFFER_SIZE;
}

char dequeue() {
    char c = uart_buffer[tail];
    tail = (tail + 1) % BUFFER_SIZE;
    return c;
}
```

---

## **10. Implement a Command Autocomplete System (Like `esh`)**
### **Task**
- If the user types `ls<TAB>`, it should autocomplete to `ls -l`.
- Use a **predefined command list** and `strncmp()` for matching.

### **Example**
```c
char *commands[] = {"ls", "exit", "help"};

void autocomplete(const char *input) {
    for (int i = 0; i < 3; i++) {
        if (strncmp(input, commands[i], strlen(input)) == 0) {
            printf("Did you mean: %s?\n", commands[i]);
        }
    }
}
```

---

### **Next Steps**
💡 **Practice these exercises before contributing to `esh`**.  
Would you like me to help with any specific one? 🚀


---


Here are **more advanced C programming exercises** that will help you build the necessary skills for contributing to `esh` (Google's UART-based shell). These focus on **system programming, process control, memory management, and embedded-like behavior**.

---

## **1. Implement `dup2()`-Based Redirection (`>` and `<`)**
### **Task**
- Implement a shell feature to redirect output (`>`) and input (`<`) using `dup2()`.
- Example:  
  ```sh
  $ ls > output.txt
  ```
  Should redirect `ls` output to `output.txt`.

### **Hint**
Use:
```c
int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
dup2(fd, STDOUT_FILENO);
```

---

## **2. Implement a `cd` Command (Using `chdir()`)**
### **Task**
- Modify your shell to support `cd <directory>`.
- Use `chdir()` to change the working directory.

### **Example**
```sh
$ cd /home/user
$ pwd
/home/user
```

---

## **3. Implement Pipelining (`|` Operator Like Bash)**
### **Task**
- Implement **command chaining with pipes**.
- Example:
  ```sh
  $ ls | grep "main"
  ```
  Should pass `ls` output to `grep`.

### **Hint**
Use:
```c
pipe(fd);
fork();
dup2(fd[1], STDOUT_FILENO);
execvp(cmd1, args);
```

---

## **4. Implement a Background Process (`&` Operator)**
### **Task**
- Modify your shell to support:
  ```sh
  $ ./myprogram &
  ```
- The command should **run in the background** (i.e., parent shell should not wait).

### **Hint**
Use:
```c
if (fork() == 0) {
    setsid(); // Detach from terminal
    execvp(argv[0], argv);
}
```

---

## **5. Implement Tab Completion (Like `esh`)**
### **Task**
- Implement **auto-suggestions** for known commands when pressing `<TAB>`.
- If user types `ls<TAB>`, autocomplete to `ls -l`.

### **Hint**
- Use `read()` in **non-canonical mode** (`termios` struct).
- Use **predefined command list** and `strncmp()`.

---

## **6. Implement a Custom Signal Handler (`kill` Command)**
### **Task**
- Implement a custom `kill` command:
  ```sh
  $ kill 1234
  ```
- This should **send a signal** to process `1234`.

### **Hint**
Use:
```c
kill(pid, SIGTERM);
```

---

## **7. Implement a Multi-Threaded Logger**
### **Task**
- Implement a **log system** that runs in a **separate thread**.
- The main program **sends logs** using a queue.

### **Hint**
Use:
```c
pthread_create(&log_thread, NULL, log_function, NULL);
pthread_mutex_lock(&lock);
pthread_mutex_unlock(&lock);
```

---

## **8. Implement Memory Pools (For Embedded-Like Efficiency)**
### **Task**
- Replace `malloc()` and `free()` with **fixed-size memory blocks**.

### **Hint**
- Use a **linked list of free blocks**.
- Allocate **fixed chunks** instead of dynamic memory.

---

## **9. Implement a `tail -f` Clone (File Monitoring)**
### **Task**
- Implement a **continuous log reader** that follows new content in a file.
- Example:
  ```sh
  $ tail -f log.txt
  ```
  Should print **new lines as they are added**.

### **Hint**
Use:
```c
lseek(fd, 0, SEEK_END); // Move to end of file
while (1) {
    read(fd, buf, sizeof(buf));
}
```

---

## **10. Implement a Virtual Filesystem (Basic `ls` and `touch`)**
### **Task**
- Implement an **in-memory filesystem** with:
  - `ls` → List files
  - `touch <file>` → Create files

### **Hint**
- Use a `struct` for **directory entries**:
  ```c
  struct File {
      char name[100];
      int size;
  };
  ```

---

### **🔥 Advanced Bonus Challenges**
✔ **Implement a Custom Heap Manager** (Like `malloc()`)  
✔ **Implement a Job Control System (`fg`, `bg`, `jobs`)**  
✔ **Implement a Userland Thread Scheduler (`setjmp/longjmp`)**  
✔ **Write a Minimalistic Debugger (`ptrace()`)**  

---

### **What Next?**
💡 Pick **any** and I'll guide you through it step by step! 🚀

---

