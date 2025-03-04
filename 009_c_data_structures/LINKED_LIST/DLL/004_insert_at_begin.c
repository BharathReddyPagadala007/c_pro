#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};



void insert_at_begin(struct Node** phead, int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	if(*phead == NULL){
		*phead = newNode;
		//return;
		//if u dont return from here the rest code gets followed
		return ;

	}

	newNode->next = *phead;
	(*phead)->prev = newNode;
	*phead = newNode;

}


void display_forward(struct Node* head){


	struct Node* temp = head;

	while(temp!=NULL){
	
	printf("%d-->",temp->data);
	temp=temp->next;
	}

	printf("NULL \n");

}

int  main(){

	struct Node* head = NULL;
	
	insert_at_begin(&head,1);
	insert_at_begin(&head,2);
	insert_at_begin(&head,3);
	insert_at_begin(&head,4);
	insert_at_begin(&head,5);
	insert_at_begin(&head,6);
	display_forward(head);



return 0;
}
