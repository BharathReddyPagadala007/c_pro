#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/types.h>

#define SHM_KEY 18965

#define SEM_KEY 19865


int main(){

   int shmid,semid;
   char* shmptr = NULL;
   struct sembuf smop;


   shmid = shmget(SHM_KEY,512, IPC_CREAT|0666);
   semid = semget(SEM_KEY,2,IPC_CREAT|0666);
   shmptr = shmat(shmid,NULL,0);

   semctl(semid,0,SETVAL,0);
   semctl(semid,1,SETVAL,0);
   smop.sem_num =0;
   smop.sem_op=-1;
   smop.sem_flg =0;

   printf("waiting for client message \n");
   semop(semid,&smop,1);

   printf("message from client : %s\n",shmptr);
   

return 0;
}
