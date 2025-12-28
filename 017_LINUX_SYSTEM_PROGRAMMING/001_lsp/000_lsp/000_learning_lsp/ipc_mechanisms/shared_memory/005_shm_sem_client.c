#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

#define SHM_KEY 25223
#define SEM_KEY 25224

int main() {
    int shmid, semid;
    char *shmptr;

    shmid = shmget(SHM_KEY, 512, 0666);
    shmptr = shmat(shmid, NULL, 0);

    semid = semget(SEM_KEY, 1, 0666);

    struct sembuf signal_op = {0, +1, 0};

    while (1) {
        printf("enter message: ");
        fgets(shmptr, 512, stdin);
        semop(semid, &signal_op, 1);   // WAKE server
    }
}

