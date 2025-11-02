#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf {
    long mtype;        // Message type (must be > 0)
    char mtext[100];   // Message text
};

int main() {
    key_t key = 5678; // Unique key for the message queue
    int msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget failed");
        exit(1);
    }

    struct msgbuf msg;
    msg.mtype = 1; // Set the message type

    printf("Enter the message to send: ");
    if (fgets(msg.mtext, sizeof(msg.mtext), stdin) == NULL) {
        perror("Error reading input");
        exit(1);
    }

    // Remove trailing newline character if present
    msg.mtext[strcspn(msg.mtext, "\n")] = '\0';

    if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Message sent: %s\n", msg.mtext);
    return 0;
}

////////////////////////////////////////////
// $ ipcrm -Q 0x0000162e
// to remove the message queuue object
