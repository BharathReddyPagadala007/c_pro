#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Queue{

  int arr[MAX];
  int front;
  int rear;
};

void init_queue(struct Queue* q){
	q->rear=-1;
	q->front=0;
}

void enqueue(struct Queue * q, int value ){

    q->rear+=1;
    q->arr[q->rear]= value;
    printf("%d added on the rear side\n",value);
}
void dequeue(struct Queue* q){
    
	int deq_val = q->arr[q->front];

	q->front +=1;

	printf("%d dequeued\n",deq_val);


}

void display(struct Queue* q){
    
	for(int i=q->front; i<=q->rear; i++){
	  printf("%d--> ",q->arr[i]);
	}

	printf("\n\n\n");

}



int main(){
	struct Queue que;
	init_queue(&que);
	enqueue(&que,10);
	enqueue(&que,11);
	enqueue(&que,12);
	enqueue(&que,13);
	enqueue(&que,14);
	display(&que);
	dequeue(&que);
	display(&que);
   







return 0;
}
