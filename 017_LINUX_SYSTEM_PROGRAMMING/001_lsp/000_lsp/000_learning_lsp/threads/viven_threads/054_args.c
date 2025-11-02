#include<stdio.h>
#include<pthread.h>

typedef struct {
    int arg1;
    char* arg2;
} thread_args;



void * print_hello(void* args){

	thread_args* argu = (thread_args*)args;

	
	printf("threadid--.>%ld-->%d...>%s\n",pthread_self(),argu->arg1,argu->arg2);
}

int main(){


  // Prepare arguments for the threads
    thread_args args1 = {1, "First"};
    thread_args args2 = {2, "Second"};
 pthread_t thread1,thread2;

 pthread_create(&thread1,NULL,print_hello,(void*)&args1);
 pthread_create(&thread2,NULL,print_hello,(void*)&args2);

 pthread_join(thread1,NULL);
 pthread_join(thread2,NULL);




return 0;
}
