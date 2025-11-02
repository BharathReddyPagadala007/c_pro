#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void*  thread1(){

	for(int i=0; i<20; i++){
	
		printf("%d---this is thraed function \n",i);
		sleep(1);
	}
	printf("thread1 execution is completed\n");
}
int main(){

	pthread_t th;

//	thread1(NULL);
	pthread_create(&th, NULL, thread1, NULL);

	for(int i=0; i<10; i++){
	
		printf("%d---this is main thread \n",i);
		sleep(1);
	}
//	printf("main thread execution is completed \n even in the  case the thread1 is not comjpleted u will thread1 gets terminated prematurely when main execution finishes\n ");

printf("main thread execution is completed\n now waiting for thread1 using pthared_join()\n ");
	pthread_join(th,NULL);


return 0;
}
