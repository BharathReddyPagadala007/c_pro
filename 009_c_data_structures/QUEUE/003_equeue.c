#include<stdio.h>

struct Queue{
int arr[10];
int rear;
int front;
};

void init_queue(struct Queue* pq){
	pq->rear = -1;
	pq->front = -1;
}

void enqueue(struct Queue* pq, int value){

	pq->rear++;
	pq->arr[pq->rear]=value;

}
void display(struct Queue* pq){

	for(int i=0; i<=(pq->rear); i++){
	
	printf("%d  -->",(pq->arr[i]));
	
	}
	printf("\n");


	

}
int main(){

	struct Queue q;
	init_queue(&q);

	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	display(&q);


return 0;
}
