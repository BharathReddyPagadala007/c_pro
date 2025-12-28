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

     printf("waiting for message from the  client \n");
     printf("receiver :: %s\n",shmptr);





return 0;
}


// this is server
// we are recieving message from the client
// we are going to  print the message 
// the disadvantage with shared memory it doesnt block even if there is no message to read or 
//  it just prints the message from the shared memory if its present
//
