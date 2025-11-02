#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/ipc.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){

	int fds[2], pid, status;

	pipe(fds);
	pid = fork();

	if(pid ==0){
	//child 
	
		char buf[20]= {0};
		//
		close(fds[1]);
		printf("waiting for message from parent\n");
		//
		read(fds[0], buf, 20);
		printf("receiver message from parent :: %s\n",buf);

	}
	else{
	
	//parent
	
		char buf[20]={0};

		close(fds[0]);
		printf("enter message for a child\n");
	
		scanf("%s",buf);
		write(fds[1], buf, strlen(buf));
	
	}
sleep(100);
	wait(&status);




return 0;
}

///////////////////////////////////////////
// why are using two buf separetely declared  inside parents and child prc
// process
//
//














