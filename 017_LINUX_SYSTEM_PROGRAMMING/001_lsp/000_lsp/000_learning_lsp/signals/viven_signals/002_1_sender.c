#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>




int main(){



	pid_t pid;

	printf("enter the pid of the recierveprocess\n");
	scanf("%d",&pid);

	
	kill(pid,SIGUSR1);

	printf("sent sigusr1  to process with pid:: %d\n",pid);


	return 0;

}
