#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(){


	int pid;

	if((pid =fork())<0){
	
		printf("fork failed\n");
		
	
	}

	if(pid ==0){
	int i=0;

	for(i=0; i<10; i++){
	
	printf("%d--->child pricess --pid = %d , ppid= %d\n",i,getpid(),getppid());
	sleep(1);
	
	
	}
	
	}else{
	int i;
	for(i=0; i<10;i++){

	printf("%d-->parent process-- pid = %d\n",i,getpid());
	sleep(1);
	
	}
	


	
	}

return 0;
}



