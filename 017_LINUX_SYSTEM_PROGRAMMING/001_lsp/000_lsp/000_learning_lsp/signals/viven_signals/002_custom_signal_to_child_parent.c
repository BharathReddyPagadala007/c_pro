#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>



void  signal_handler(int sig){

	if(sig == SIGUSR1)
	printf("sigusr1 receiver from parent to child");
}



int main(){
 
	pid_t pid = fork();

	if(pid==0){
		printf("child --process\n");

		printf("reciver--proicess\n");
		
		//
		//signal behaviour is changed here

		signal(SIGUSR1,signal_handler);



		int i=0;
		while(i<10){
			sleep(1);
			printf("child world %d\n",i++);
		
		}
	
	
	}else{
 printf("Sender process started. Sending signal to receiver (PID: %d).\n", pid);	
 sleep(2);


 kill(pid,SIGUSR1);
  wait(NULL);  // Wait for any child process to terminate
        printf("Sender process exiting after child process terminates.\n");	
	
	}


return 0;
}
