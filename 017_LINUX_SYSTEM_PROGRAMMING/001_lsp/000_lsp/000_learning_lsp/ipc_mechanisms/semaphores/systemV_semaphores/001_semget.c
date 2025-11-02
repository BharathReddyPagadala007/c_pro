#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    key_t key = 1234; // A unique key to identify the semaphore set.
    int semid;
    int nsems = 1; // Number of semaphores in the set.
    int semflg = IPC_CREAT | 0666; // Create with read/write permissions.

    // Step 1: Create the semaphore set.
    semid = semget(key, nsems, semflg);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    printf("Semaphore set created with ID: %d\n", semid);

    // Step 2: Access the existing semaphore set.
    semid = semget(key, nsems, 0); // Note: semflg = 0
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    printf("Accessed semaphore set with ID: %d\n", semid);

    return 0;
}

