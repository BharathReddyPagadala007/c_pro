#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    key_t key = 1234;  // Example key
    int msgflg = IPC_CREAT | 0666;  // Create queue with read-write permissions for all

    int msqid = msgget(key, msgflg);
    if (msqid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Message queue created with ID: %d\n", msqid);
    return 0;
}

