/*
 *
 *
 *
 *   BASIC SHELL 
 *   ----------
 *   Features:
 *   1. reads user input                           ---   getline()   
 *   2. splits input into arguments                ---   strtok()
 *   3. creates a child process         	   ---   fork()
 *   4. executes the command                       ---   execvp()
 *   5. waits for the child process to complete    ---   waitpid()
 *
 *
 */
//-------------------------------------

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>



#define MAX_INPUT 1024
#define MAX_ARGS 100


void execute_command(char* input);


//--------------------------------------

int main(){

  char input[MAX_INPUT];

  while(1){
  
  
	  printf("myshell>  ");

	  if(fgets(input,MAX_INPUT,stdin) == NULL){
		  break;  // exit on ctrl + D
	  
	  }


      execute_command(input);
  }


  printf("main returns \n");
return 0;
}

//-------------------------------------------------

void execute_command(char* input)
{
        int i=0;
	char* args[MAX_ARGS];

	char* token =  strtok(input," \t\n");


	while(token!= NULL && i < MAX_ARGS -1){

		args[i++]= token;
		token = strtok(NULL, " \t\n");
	
	}
	args[i]= NULL;
	
	if(args[0]== NULL){
	  return ;
	}


	for(int j=0; j<i; j++)
	{
		printf("executing \n%s\n",args[j]);
	}




	    // Handle "cd" command separately
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd failed");
        }
        return;
    }
/*
	pid_t pid = fork();

	if(pid<0){
	 perror("fork failed");
	 exit(1);
	}else if(pid== 0){
	 printf("child creation succesful\n");
	
	}
*/

	//-------------------------
	 // Fork and execute other commands
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) { // Child process
        execvp(args[0], args);
        perror("exec failed"); // If exec fails
        exit(1);
    } else { // Parent process
        waitpid(pid, NULL, 0);
    }




}

























