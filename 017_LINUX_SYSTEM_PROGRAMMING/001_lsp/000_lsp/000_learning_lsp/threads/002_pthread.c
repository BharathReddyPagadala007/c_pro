#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void*  thread1(){

	while(1){
	
		printf("this is thraed function \n");
		sleep(1);
	}
}
int main(){

	pthread_t th;

//	thread1(NULL);
	pthread_create(&th, NULL, thread1, NULL);

	while(1){
	
		printf("this is main thread \n");
		sleep(1);
	}

return 0;
}
