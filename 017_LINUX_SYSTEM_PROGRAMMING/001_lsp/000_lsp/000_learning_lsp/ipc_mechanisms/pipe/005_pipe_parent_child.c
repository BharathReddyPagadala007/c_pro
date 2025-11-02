#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>



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
  
	  printf("fork success");
  }
	     

  if(pid==0){
    printf("===========================\n");
    printf("ur in child process\n");
    printf("pid -->%d\n",pid);
    printf("%d\n",getpid());
    //printf("%d\n",getppid)();
    printf("===========================\n");
  
  }
  else{
  
    printf("===========================\n");
    printf("pid -->%d\n",pid);
    printf("ur in parent process  processi---> \n");
    printf("%d\n",getpid());
  
    printf("===========================\n");
  
  }

  


  return 0;

}
