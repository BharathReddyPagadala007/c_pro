#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_KEY 25223
#define SEM_KEY 25224

int main() {
    int shmid, semid;
    char *shmptr;

    shmid = shmget(SHM_KEY, 512, IPC_CREAT | 0666);
    shmptr = shmat(shmid, NULL, 0);

    semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);

    struct sembuf wait_op = {0, -1, 0}; // BLOCK until client posts

    while (1) {
        semop(semid, &wait_op, 1);   // BLOCKS here
        printf("receiver :: %s\n", shmptr);
    }
}

