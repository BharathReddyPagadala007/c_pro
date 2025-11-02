#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(){

	int pc_fd[2];
	int cp_fd[2];
	pid_t pid;

	if(pipe(pc_fd)==-1 || pipe(cp_fd)==-1){
	 perror("fork failed");
	 exit(1);
	}

	pid = fork();

	if(pid<0){
	perror("fork failed");
	exit(1);
	}

	if(pid ==0){
		//child process
		// read from parent to child
		// close write pc
		// close read cp

		close(cp_fd[0]);
		close(pc_fd[1]);

		char message[100];
		char response[]= "acknowledged by child";


		read(pc_fd[0],message,sizeof(message));
		printf("child:: received message from parent :: %s\n",message);

		printf("child:: sending acknowledgement to parent \n	");
		write(cp_fd[1],response,strlen(response)+1);

		close(cp_fd[1]);
		close(pc_fd[0]);


		
	
	
	}else{
		//paremt process
		// write from parent to child 
		// read pc must be close
		// write cp must be closed


	
		close(pc_fd[0]);
		close(cp_fd[1]);

		char message[] = "message from parent";
		char response[100];



		printf("parent :: sending message to child\n");
		write(pc_fd[1],message,strlen(message)+1);

		read(cp_fd[0],response,sizeof(response));
		printf("parent :: receiver response from child :: %s\n",response);

		close(pc_fd[1]);
		close(cp_fd[0]);
	
	}


return 0;
}
