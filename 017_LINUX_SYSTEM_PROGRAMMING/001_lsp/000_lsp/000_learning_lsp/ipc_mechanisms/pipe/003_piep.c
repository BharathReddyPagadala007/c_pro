#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>



int
main(int argc, char* argv[]){

	int pipefd[2];
	pid_t cpid;
	char buf;  //buf is a charachter only we are not using an array

	if(argc!=2){
	fprintf(stderr, "usage : %s <string>\n",argv[0]);
	exit(EXIT_FAILURE);
	}

	cpid = fork();
	if(cpid == -1){

		perror("fork");

		exit(EXIT_FAILURE);
	}


	/////////////////////////////////////////
	// child reads from pipe
	// parent writes argv[1 ] to pipe
	

	if(cpid ==0){
		close(pipefd[1]);

		while(read(pipefd[0],&buf,1)>0){
			write(STDOUT_FILENO,&buf,1);
			write(STDOUT_FILENO,"\n",1);
			close(pipefd[0]);
			_exit(EXIT_SUCCESS);

		}
	} else{

		close(pipefd[0]);
		write(pipefd[1],argv[1], strlen(argv[1]));
			write(STDOUT_FILENO,"\n",1);
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);

	
	
	
	}

return 0;
}















/*
























//////////////////////////////////////////////////////////////
//
  The following program creates a pipe, and then fork(2)s to create
       a  child  process; the child inherits a duplicate set of file de‐
       scriptors that refer to the same pipe.  After the  fork(2),  each
       process  closes the file descriptors that it doesn't need for the
       pipe (see pipe(7)).  The parent then writes the string  contained
       in the program's command-line argument to the pipe, and the child
       reads this string a byte at a time from the pipe and echoes it on
       standard output.









*/
