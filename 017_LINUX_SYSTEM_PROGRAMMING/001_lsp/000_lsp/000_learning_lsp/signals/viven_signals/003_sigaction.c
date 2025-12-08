#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_sigint(int sig){

	printf("caught the signal sigint %d, i\n",sig);

	//_exit(0); 
	
	// if u use exit the program will exit after catching the signal

}

int main(){

	struct sigaction sa;

	sa.sa_handler = handle_sigint;
	sa.sa_flags =0;
	sigemptyset(&sa.sa_mask); //dont block any other signal
	
	sigaction(2,&sa, NULL);


	printf("press ctrl + c inorder to invoke sigint  {sigaction handler}\n");
	
	while(1){
	
		printf("waiting for signal \n");
		sleep(5);

	
	}


return 0;
}


///////////////////
//
//
//   inorder to kill the process open other terminal 
//   ps -ef | grep a.out
//   find the pid of process or print in the program itself 
//   and 
//   kill -9 [pid]
//
//   this is terminate the process 
