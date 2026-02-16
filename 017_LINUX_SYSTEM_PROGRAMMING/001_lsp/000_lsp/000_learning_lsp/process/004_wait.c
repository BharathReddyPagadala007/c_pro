
// man 2 wait
//
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>



int main(){
	int pid,stat;

	pid = fork();  // blunder pid == fork()

	if(pid ==0){
		int i=0;

		for(i=0; i<10; i++){
			printf("tis is child process-->%d\n",i);
			sleep(1);
		
		}
		printf("child process execution complete\n");
		exit(1);
	
	}else{

		int i=0;

		for(i=0; i<5; i++){
			printf("this is parent process -->%d\n",i);
			sleep(1);
		
		
		}
		printf("parent process execution complete\n");
	}

	printf("waiting for child process to complete\n");
	wait(&stat);
	printf("child exited with code : %d\n",WEXITSTATUS(stat));

return 0;
}
