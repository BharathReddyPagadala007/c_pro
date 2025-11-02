#include<stdio.h>
#include<pthread.h>


int global;
int loop=10000;
pthread_mutex_t mtx;



////////////////////////////////////////////////////////////
void* thread1(void * args){
int i, local;
for(i=0; i<loop; ++i){
	//critical section
pthread_mutex_lock(&mtx);
  local = global;
  ++local;
  global= local;
pthread_mutex_unlock(&mtx);
}

}
////////////////////////////////////////////////////////////
void* thread2(void * args){
int i, local;
for(i=0; i<loop; ++i){
pthread_mutex_lock(&mtx);
  local = global;
  ++local;
  global= local;
pthread_mutex_unlock(&mtx);
}

}
////////////////////////////////////////////////////////////

int main(){

	pthread_t th1,th2;
	int i,local;
	void * ret;

	pthread_create(&th1,NULL, thread1, NULL);
	pthread_create(&th2,NULL, thread2, NULL);

	for(i=0; i<loop; i++){
pthread_mutex_lock(&mtx);
	local = global;
	++local;
	global= local;
pthread_mutex_unlock(&mtx);
	}

	pthread_join(th1, &ret);
	pthread_join(th2, &ret);

	printf("global data :: %d\n",global);

return 0;
}
////////////////////////////////////////////////////////////

