#include<stdio.h>
#include<stdlib.h>


struct Node{
 int data;
 struct Node* next;
};


struct Stack{
struct Node* top;
};

void init_stack(struct Stack* st){
	st->top = NULL;
}

void push(struct Stack* st, int value){
  
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = value;
	newNode->next = st->top;
	st->top = newNode;
	printf("%d pushed \n",value);

}

void display(struct Stack* st){

	struct Node* current = st->top;
	printf("display stack :: \n");

	while(current!=NULL){
	  printf("%d  ",current->data);
	  current = current->next;
	}
	printf("\n");
}

void pop(struct Stack * st){
  struct Node* temp = st->top;
  int popped_value = temp->data;
  st->top = st->top->next;

  free(temp);
  printf("popped value --> %d\n",popped_value);

}


int main(){
  struct Stack st;
  init_stack(&st); 
  push(&st,10);
  push(&st,11);
  push(&st,12);
  push(&st,13);
  display(&st);
  pop(&st);
  display(&st);




return 0;
}
