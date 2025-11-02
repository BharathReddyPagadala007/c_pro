#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHM_KEY 12345   // Hard key for the shared memory segment

int main() {
    // Get the shared memory segment using shmget
    int shmid = shmget(SHM_KEY, 0, 0666);  // 0 size since we're only attaching
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    printf("Shared memory segment found with ID: %d\n", shmid);

    // Attach the shared memory segment to the process's address space
    void *shm_ptr = shmat(shmid, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }
    printf("Shared memory segment attached at address: %p\n", shm_ptr);

    // Reading data from the shared memory segment
    char *data = (char *)shm_ptr;
    printf("Data in shared memory: %s\n", data);

    // Detach the shared memory segment when done
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    printf("Shared memory segment detached.\n");

    return 0;
}

