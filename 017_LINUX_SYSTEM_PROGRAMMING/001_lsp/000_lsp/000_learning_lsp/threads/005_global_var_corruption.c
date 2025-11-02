#include<stdio.h>
#include<pthread.h>
int global;
int loop=10000;

void* thread1(void * args){
int i, local;
for(i=0; i<loop; ++i){
  local = global;
  ++local;
  global= local;
}

}
void* thread2(void * args){
int i, local;
for(i=0; i<loop; ++i){
  local = global;
  ++local;
  global= local;
}

}

int main(){

	pthread_t th1,th2;
	int i,local;
	void * ret;

	pthread_create(&th1,NULL, thread1, NULL);
	pthread_create(&th2,NULL, thread2, NULL);

	for(i=0; i<loop; i++){
	local = global;
	++local;
	global= local;
	}

	pthread_join(th1, &ret);
	pthread_join(th2, &ret);

	printf("global data :: %d\n",global);

return 0;
}

