#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void * print_thread_id(void* arg){

	printf("id thread == %lu -\n",pthread_self());



}

int main()
{


	pthread_t threads[5];

	for(int i=0; i<5; i++){
	pthread_create(&threads[i],NULL,print_thread_id,NULL);
	
	}
	    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL); // Wait for all threads to complete
    }
}

/////////////////////////////////////////////////
//
/*
 *  The  pthread_create() function starts a new thread in the calling process.  The new thread starts execution   
       by invoking start_routine(); arg is passed as the sole argument of start_routine().

       The new thread terminates in one of the following ways:

       * It calls pthread_exit(3), specifying an exit status value that is available to another thread in the same   
         process that calls pthread_join(3).

       * It  returns  from start_routine().  This is equivalent to calling pthread_exit(3) with the value supplied   
         in the return statement.

       * It is canceled (see pthread_cancel(3)).

       * Any of the threads in the process calls exit(3), or the main thread performs a return from main().   This   
         causes the termination of all threads in the process.

       The  attr  argument points to a pthread_attr_t structure whose contents are used at thread creation time to   
       determine attributes for the new thread; this structure is initialized using pthread_attr_init(3)  and  re‐   
       lated functions.  If attr is NULL, then the thread is created with default attributes.

       Before  returning,  a  successful  call  to  pthread_create() stores the ID of the new thread in the buffer   
       pointed to by thread; this identifier is used to refer to the thread in subsequent calls to other  pthreads   
       functions.

       The new thread inherits a copy of the creating thread's signal mask (pthread_sigmask(3)).  The set of pend‐   
       ing signals for the new thread is empty (sigpending(2)).  The new thread  does  not  inherit  the  creating   
       thread's alternate signal stack (sigaltstack(2)).

 *
 *
 *
 *
 *
 *
 */
