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

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Sender: Message Queue Created with ID: %d\n", msgid);

    // Prepare message
    msg.msg_type = 1;
    printf("Enter the message to send: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);
    msg.msg_text[strcspn(msg.msg_text, "\n")] = 0; // Remove trailing newline

    // Send message
    if (msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Sender: Message sent successfully!\n");
    return 0;
}

