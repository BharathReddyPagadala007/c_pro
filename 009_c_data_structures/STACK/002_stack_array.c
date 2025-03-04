#include<stdio.h>
#define MAX 10


struct Stack {
 int arr[MAX];
 int top;
};



void init_stack(struct Stack* st){

	st->top = -1;
}

void push(struct Stack* st, int value){
	st->top++;
	st->arr[st->top]=value;
}


void pop(struct Stack* st){
	printf("popped elemnt --> %d\n",st->arr[st->top]);
	st->top--;
}

void peek(struct Stack* st){
 printf("top peek elemen --> %d\n",st->arr[st->top]);
}
void display(struct Stack* st){
	printf("stack elements :: \n");
	for(int i=0; i<= st->top; i++){
	 printf("  %d  -->",st->arr[i]);
	}
	printf("\n");

}
int main(){

	struct Stack st;
	init_stack(&st);
	push(&st,10);
	push(&st,11);
	push(&st,12);
	push(&st,13);
	push(&st,14);
	push(&st,15);
	display(&st);
	pop(&st);
	display(&st);
	
return 0;
}


