#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>

#define SHM_KEY        12345
#define SHM_SIZE 	1024


int main(){

	int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);

	printf("shared memory segment craeted with id :: %d\n",shmid);

	void* shm_ptr = shmat(shmid,NULL,0);
	 printf("Shared memory segment attached at address: %p\n", shm_ptr);

	    char *data = (char *)shm_ptr;
    snprintf(data, SHM_SIZE, "Hello from shared memory!");

    /*
  if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }
    printf("Shared memory segment detached.\n");
*/
return 0;
}
