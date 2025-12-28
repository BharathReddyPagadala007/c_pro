#include<stdio.h>
#include<pthread.h>

void *print_xs(void* unsused){
	while(1){
	
		fputc('x',stderr);
	}
	
	return NULL;
}


int main(){
	pthread_t thread_id;

	

	if (pthread_create(&thread_id, NULL, &print_xs, NULL)){
	
	printf("thread craetion failed \n");
	return 1;
	
	}
	printf("thread created\n");

return 0;

}
