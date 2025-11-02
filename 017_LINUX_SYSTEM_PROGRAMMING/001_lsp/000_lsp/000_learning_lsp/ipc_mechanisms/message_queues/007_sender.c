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

