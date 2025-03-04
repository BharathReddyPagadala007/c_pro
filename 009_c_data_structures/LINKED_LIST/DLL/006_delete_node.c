#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};



void insert_at_end(struct Node** phead, int value){
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

	struct Node* temp = *phead;

	while(temp->next!=NULL){
	temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}


void display_forward(struct Node* head){


	struct Node* temp = head;

	while(temp!=NULL){
	
	printf("%d-->",temp->data);
	temp=temp->next;
	}

	printf("NULL \n");

}
void delete_node(struct Node** phead,int value){

	if(*phead == NULL) return ;

	struct Node* temp = *phead;

	while(temp!=NULL && temp->data!=value){
	     temp = temp->next;
	}

	if(temp == NULL){
	
	 printf("item not found\n");
	 return;
	}

	if(temp->prev!= NULL){
	 temp->prev->next = temp->next;
	
	}else{
	  *phead = temp->next;
	
	}

	if(temp->next!=NULL){
	temp->next->prev= temp->prev;
	
	}

	free(temp);




}

int  main(){

	struct Node* head = NULL;
	
	insert_at_end(&head,1);
	insert_at_end(&head,2);
	insert_at_end(&head,3);
	insert_at_end(&head,4);
	insert_at_end(&head,5);
	insert_at_end(&head,6);
	display_forward(head);
	delete_node(&head,4);
	display_forward(head);


return 0;
}
