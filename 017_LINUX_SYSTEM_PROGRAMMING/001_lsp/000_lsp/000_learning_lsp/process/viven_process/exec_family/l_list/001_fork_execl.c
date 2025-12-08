#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){


	pid_t pid = fork();


	if(0 == pid){
	
		printf("before executing execl::\n");
		execl("/bin/ls","ls","-l",NULL);
		perror("execl failed");


		return 1;
	

	}else{
		printf("parent ::: child_pid = %d\n",pid);
	
		printf("parent:: waiting for child proces to get completed\n");
		wait(NULL);

		printf("parent:: child just now completed\n");
		
	
	
	}


return 0;
}
