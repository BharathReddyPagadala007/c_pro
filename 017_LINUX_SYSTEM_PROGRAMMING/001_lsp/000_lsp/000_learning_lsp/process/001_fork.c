#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(){


	int pid;

	if((pid =fork())<0){
	
		printf("fork failed\n");
		
	
	}

	if(pid ==0){
	printf("child pricess --pid = %d , ppid= %d\n",getpid(),getppid());
	
	}else{
	
	printf("parent process-- pid = %d\n",getpid());
	
	}

return 0;
}



