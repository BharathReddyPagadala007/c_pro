#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int shared_var =0;

pthread_mutex_t mutex;

void* print_id_thread(void* arg){

	pthread_mutex_lock(&mutex);

	for(int i=0;i<1000;i++) shared_var++;

	printf("%lu iii\n",pthread_self());
	pthread_mutex_unlock(&mutex);



}
int main(){

	pthread_t pthread1;
	pthread_t pthread2;
	pthread_mutex_init(&mutex,NULL);


	pthread_create(&pthread1,NULL,print_id_thread,NULL);
	pthread_create(&pthread2,NULL,print_id_thread,NULL);

	pthread_join(pthread1,NULL);
	pthread_join(pthread2,NULL);

		pthread_mutex_destroy(&mutex);
		printf("sgha--> %d\n",shared_var);

	   printf("Main thread exiting.\n");

return 0;

}
