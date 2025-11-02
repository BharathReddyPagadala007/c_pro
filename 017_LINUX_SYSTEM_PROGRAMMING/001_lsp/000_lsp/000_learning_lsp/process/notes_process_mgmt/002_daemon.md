### ✅ **Creating a Daemon Process in C**  

A **daemon** is a background process that runs without direct user interaction, often used for tasks like logging, monitoring, or server management. Unlike regular processes, daemons have no controlling terminal.

---

## 📌 **Steps to Create a Daemon Process**

1. **Fork the Process:**  
    - Create a child using `fork()` and terminate the parent using `exit()` to ensure the child runs independently.

2. **Create a New Session:**  
    - Use `setsid()` to create a new session and become a session leader, detaching from the terminal.

3. **Change the Working Directory:**  
    - Use `chdir("/")` to set the root directory (`/`) as the working directory, preventing issues with mounted filesystems.

4. **Close File Descriptors:**  
    - Close `stdin`, `stdout`, and `stderr` using `close()` to prevent terminal output.

5. **Redirect Standard Streams:**  
    - Optionally redirect `stdin`, `stdout`, and `stderr` to `/dev/null`.

---

## 🧑‍💻 **C Program to Create a Daemon Process**

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void create_daemon() {
    pid_t pid = fork();

    // Step 1: Fork and exit parent
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        printf("Parent process terminated. Daemon PID: %d\n", pid);
        exit(EXIT_SUCCESS);
    }

    // Step 2: Create a new session and become a session leader
    if (setsid() < 0) {
        perror("Failed to create new session");
        exit(EXIT_FAILURE);
    }

    // Step 3: Fork again to prevent re-acquiring a terminal
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Step 4: Set file permissions
    umask(0);

    // Step 5: Change working directory to root
    if (chdir("/") < 0) {
        perror("Failed to change directory to root");
        exit(EXIT_FAILURE);
    }

    // Step 6: Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Step 7: Optionally redirect standard file descriptors to /dev/null
    open("/dev/null", O_RDONLY); // stdin
    open("/dev/null", O_WRONLY); // stdout
    open("/dev/null", O_WRONLY); // stderr

    // Step 8: Daemon-specific logic
    while (1) {
        // Example: Writing to a log file
        FILE *fp = fopen("/tmp/daemon.log", "a+");
        if (fp == NULL) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }
        fprintf(fp, "Daemon is running. PID: %d\n", getpid());
        fclose(fp);
        sleep(10); // Sleep to simulate periodic task
    }
}

int main() {
    create_daemon();
    return 0;
}
```

---

## 📊 **Explanation**  

- **Fork Twice:**  
  - First fork detaches the child from the parent.  
  - Second fork ensures it cannot acquire a terminal again.  

- **setsid():**  
  - Creates a new session and sets the process as its leader, preventing the process from being controlled by a terminal.  

- **umask(0):**  
  - Resets file permissions to ensure the daemon has unrestricted access to files.  

- **Redirecting to `/dev/null`:**  
  - Prevents the daemon from outputting to the terminal.  

- **Logging:**  
  - Logs its activity to `/tmp/daemon.log`.

---

## 🧪 **Testing the Daemon**

1. **Compile:**  
    ```bash
    gcc daemon_example.c -o daemon_example
    ```

2. **Run:**  
    ```bash
    ./daemon_example
    ```

3. **Verify:**  
    - Check if the daemon is running using:  
    ```bash
    ps aux | grep daemon_example
    ```
    - Monitor the log file:  
    ```bash
    tail -f /tmp/daemon.log
    ```

---

## 🚀 **Key Takeaways**  

- Daemons run without user interaction.  
- Useful for background tasks like logging, monitoring, or managing network services.  
- Proper error handling is crucial in daemon processes.  

