#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sigint_handler(int signum){

	printf("reciever sigint in the signal handler\n");

	sigset_t mask;





}


int main(){

	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sa.sa_flags =0;


	sigaction(SIGINT, &sa,NULL);




return 0;
}
