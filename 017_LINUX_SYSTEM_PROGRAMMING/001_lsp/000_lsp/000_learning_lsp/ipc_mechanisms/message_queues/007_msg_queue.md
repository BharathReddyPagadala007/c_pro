Using a hard-coded key instead of `ftok` simplifies the implementation and avoids dependencies on an external file. This approach is useful in scenarios where unrelated processes agree on a predefined key for communication.

Here's how you can modify the sender and receiver programs to use a hard-coded key:

---

### Sender Program (`sender.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 100
#define MESSAGE_QUEUE_KEY 1234 // Hard-coded key

// Define the message structure
struct message {
    long type;             // Message type
    char text[MESSAGE_SIZE]; // Message text
};

int main() {
    int msgid;
    struct message msg;

    // Create or get the message queue using the hard-coded key
    msgid = msgget(MESSAGE_QUEUE_KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    msg.type = 1; // Set the message type

    while (1) {
        printf("Sender: Enter a message to send (type 'exit' to quit): ");
        fgets(msg.text, MESSAGE_SIZE, stdin);
        msg.text[strcspn(msg.text, "\n")] = '\0'; // Remove newline character

        // Send the message
        if (msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1) {
            perror("msgsnd failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(msg.text, "exit") == 0) {
            break;
        }
    }

    printf("Sender: Exiting...\n");
    return 0;
}
```

---

### Receiver Program (`receiver.c`)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 100
#define MESSAGE_QUEUE_KEY 1234 // Hard-coded key

// Define the message structure
struct message {
    long type;             // Message type
    char text[MESSAGE_SIZE]; // Message text
};

int main() {
    int msgid;
    struct message msg;

    // Access the message queue using the hard-coded key
    msgid = msgget(MESSAGE_QUEUE_KEY, 0666);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive a message of type 1
        if (msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        }

        printf("Receiver: Received message: %s\n", msg.text);

        if (strcmp(msg.text, "exit") == 0) {
            break;
        }
    }

    // Cleanup: Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl failed");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Exiting...\n");
    return 0;
}
```

---

### Key Points:
1. **Hard-Coded Key**:
   - The sender and receiver use the same hard-coded key (`1234` in this example) to access the same message queue.
   - Ensure the key is unique system-wide to avoid conflicts with other IPC resources.

2. **Message Queue Creation**:
   - The sender creates the queue using `IPC_CREAT`.
   - The receiver only accesses the existing queue.

3. **Queue Cleanup**:
   - The receiver removes the queue after processing the `exit` message.

---

### Steps to Run:
1. Compile the sender and receiver programs:
   ```bash
   gcc -o sender sender.c
   gcc -o receiver receiver.c
   ```

2. Run the **receiver** process first in one terminal:
   ```bash
   ./receiver
   ```

3. Run the **sender** process in another terminal:
   ```bash
   ./sender
   ```

4. Send messages from the sender terminal. The receiver will display them. Type `exit` in the sender to terminate communication.

---

### Advantages of Hard-Coded Key:
- **Simplicity**: No need to manage or create external files.
- **Robustness**: Reduces chances of errors like "No such file" when using `ftok`.

### Disadvantages:
- **Key Conflicts**: If another application uses the same key, there might be unexpected behavior.
- **Less Dynamic**: Changing the key requires modifying the source code and recompiling.

By using a carefully chosen hard-coded key, you can ensure reliable communication between unrelated processes.
