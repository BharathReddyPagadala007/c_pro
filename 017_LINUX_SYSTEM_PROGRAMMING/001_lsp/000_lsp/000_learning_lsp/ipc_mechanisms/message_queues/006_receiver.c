#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

// Define message structure
struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = 1234; // Fixed key
    int msgid;
    struct message msg;

    // Access message queue
    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Message Queue Accessed with ID: %d\n", msgid);

    // Receive message
    if (msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0) == -1) {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Message received: %s\n", msg.msg_text);
    return 0;
}

