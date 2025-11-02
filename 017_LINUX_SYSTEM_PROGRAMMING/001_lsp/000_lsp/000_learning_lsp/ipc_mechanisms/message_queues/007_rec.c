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

