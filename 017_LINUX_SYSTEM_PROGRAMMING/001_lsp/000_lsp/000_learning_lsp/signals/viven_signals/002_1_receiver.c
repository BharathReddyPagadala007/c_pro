#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


void signal_handler(int sig){
	if(sig == SIGUSR1){
	printf("%d--sigusr1\n",sig);
	
	}


}




int main(){

	signal(SIGUSR1,signal_handler);
	printf("receiver process running pi:: %d\n",getpid());


	while(1){
	
		printf("about tp pause the process and wait for a signal\n");
	 pause();
	}



return 0;
}
