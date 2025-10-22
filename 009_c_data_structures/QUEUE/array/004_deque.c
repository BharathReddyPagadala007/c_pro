#include<stdio.h>

struct Queue{
int arr[10];
int rear;
int front;
};

void init_queue(struct Queue* pq){
	pq->rear = -1;
	pq->front = 0;
}

void enqueue(struct Queue* pq, int value){

	pq->rear++;
	pq->arr[pq->rear]=value;

}
void display(struct Queue* pq){

	for(int i=(pq->front); i<=(pq->rear); i++){
	
	printf("%d  -->",(pq->arr[i]));
	
	}
	printf("\n");

}
void dequeue(struct Queue* pq){

	pq->front = pq->front +1;



}
int main(){

	struct Queue q;
	init_queue(&q);

	enqueue(&q,10);
	enqueue(&q,20);
	enqueue(&q,30);
	enqueue(&q,32);
	enqueue(&q,47);
	enqueue(&q,55);
	display(&q);
	dequeue(&q);
	dequeue(&q);
	display(&q);


return 0;
}
