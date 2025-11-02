#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define SHM_KEY 25223


int main(){


    int shmid;
    char* shmptr = NULL;


     shmid = shmget(SHM_KEY,512,IPC_CREAT | 0666);
     shmptr = shmat(shmid,NULL,0);

     /*
      *  void *shmat(int shmid, const void *shmaddr, int shmflg);
      */

     printf("waiting for message for client \n");
     printf("receiver :: %s\n",shmptr);




return 0;
}
