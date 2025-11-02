#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>



void handler_for_sigint(int sig){
	printf("\nCaught signal %d (SIGINT). Exiting gracefully.\n", sig);
    exit(0); // Exit the program


}



int main(){


	signal(SIGINT ,handler_for_sigint);  //	SIGINT 2
					     //
	
	printf("performing some work---->\n");
	int count=0;
	

	while(1){
	
		printf("working ---task--%d\n",count);
		sleep(2);
		count++;
	
	}



return 0;
}
