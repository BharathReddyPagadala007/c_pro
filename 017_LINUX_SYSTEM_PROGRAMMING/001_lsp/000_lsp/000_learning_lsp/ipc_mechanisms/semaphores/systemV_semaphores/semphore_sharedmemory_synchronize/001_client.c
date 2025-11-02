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


   shmid = shmget(SHM_KEY,512, 0);
   semid = semget(SEM_KEY,2,0);
   shmptr = shmat(shmid,NULL,0);

   printf("enter the message for server::\n");
   scanf("%s",shmptr);

   smop.sem_num =0;
   smop.sem_op=1;
   smop.sem_flg =0;

   printf("message sent\n");
   semop(semid,&smop,1);

   

return 0;
}
