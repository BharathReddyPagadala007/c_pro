#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
// Define message structure
struct message {
    long msg_type;       // Message type, must be > 0
    char msg_text[100];  // Message text
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    // Generate unique key
    key = ftok("msgqueue_file", 65); // "msgqueue_file" should exist or can be created
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    } 
    
    
    
    msgid = msgget(key, 0666);



    printf("Receiver: Message Queue Accessed with ID: %d\n", msgid);

    printf("Receiver: Waiting for a message...\n");

msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0);
 printf("Receiver: Message received successfully: Type=%ld, Text=%s\n", msg.msg_type, msg.msg_text);

    return 0;
}
