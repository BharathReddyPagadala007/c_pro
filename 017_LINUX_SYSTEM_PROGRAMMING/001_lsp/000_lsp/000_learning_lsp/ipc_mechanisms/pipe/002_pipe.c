#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>



int main(){

	int pipefd[2];

	pid_t pid;
	char write_msg[]="hello0 from parent| \n";
	char read_msg[100];



	//create the pipe

	if(pipe(pipefd)==-1){
	  perror("pipe failed");
	  exit(1);
	}


	//fork the process
	
	pid = fork();
	
	if(pid<0){
		perror("fork faiekld");
		exit(1);
	}


	if(pid>0){

		close(pipefd[0]);
		printf("parent :: writing to the pipe :: %s\n",write_msg);
		write(pipefd[1],write_msg, strlen(write_msg)+1);
		close(pipefd[1]);
	
	}else{
	
	
		//child process

		close(pipefd[1]);


		read(pipefd[0],read_msg,sizeof(read_msg));

		printf("child :: read from pipe:: %s\n", read_msg);

		close(pipefd[0]);
	
	}



return 0;
}
