#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* print_id_thread(void* arg){

	printf("%lu  <-- ID \n",pthread_self());



}
int main(){

	pthread_t pthread1;
	pthread_t pthread2;


	printf("main:: %lu  <-- ID \n",pthread_self());


	pthread_create(&pthread1,NULL,print_id_thread,NULL);
	pthread_create(&pthread2,NULL,print_id_thread,NULL);

	pthread_join(pthread1,NULL);
	pthread_join(pthread2,NULL);


	   printf("Main thread exiting.\n");

return 0;

}
