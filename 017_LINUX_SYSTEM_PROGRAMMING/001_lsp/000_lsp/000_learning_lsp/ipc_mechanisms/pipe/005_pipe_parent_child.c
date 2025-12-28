#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>




int main(){

  int fds[2];

  int ret =pipe(fds);

  if(ret==0){
  printf("pipe cdreated successfully\n");
  }
  if(ret == -1){
  printf("pipe craety failed\n");
  }

  // child creation using fork
  //
  /*
   *
       fork - create a child process

       #include <sys/types.h>
       #include <unistd.h>

       pid_t fork(void);
        fork returns pid of child process


       */

  pid_t pid;  //sys/types.h

  pid = fork();

  if(pid<0){
	  printf("fork failed\n");
  
  }else{
  
	  printf("fork success\n");
  }
	     

  if(pid==0){
 /*
    printf("CHILD::===========================\n");
    printf("CHILD::ur in child process\n");
    printf("CHILD::pid -->%d\n",pid);
    printf("CHILD::%d\n",getpid());
    //printf("%d\n",getppid)();
    printf("CHILD::===========================\n");
*/
    char buf[20]={0};
    close(fds[1]);  //closing write fd
    open(fds[0]);
    printf("CHILD::waiting for parent to enter message\n");
    read(fds[0],buf,20);
    printf("CHILD::received message = %s\n",buf);
    close(fds[0]);
    open(fds[1]);



  
  }
  else{
 /* 
    printf("PARENT::===========================\n");
    printf("PARENT::pid -->%d\n",pid);
    printf("PARENT::ur in parent process  processi---> \n");
    printf("PARENT::%d\n",getpid());
  
    printf("PARENT::===========================\n");
  */


  char buf[20]= {0};

  close(fds[0]); //close read fd
  printf("PARENT::enter message to be sent for child :\n");
  write(fds[1],buf,20);
  printf("PARENT::mesage sent\n");

  }

  


  return 0;

}
