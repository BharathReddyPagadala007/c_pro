#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int signum){
	printf("SIGINT receiver ...exiting programmmm---\n");
	int i=0;
	while(i<11){
		printf("----sigint_handler--->%d\n",i);
		i++;
		sleep(2);
	
	}
	exit(0);




}


int main(){


	struct sigaction sa;

	sa.sa_handler=   sigint_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	


	sigaction(SIGINT,&sa,NULL);


	while(1){
	printf("waiting for sigint\n");
	sleep(1);
	}



return 0;
}
