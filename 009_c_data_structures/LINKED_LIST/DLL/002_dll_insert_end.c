#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
struct node* prev;
struct node* next;

};

/////////////////////////////////////////////////////////////////////

// create a  node

struct node* create_node(int value){

	struct node* new_node = (struct node* )malloc(sizeof(struct node));

       if (!new_node) {
       	 printf("Memory allocation failed\n");
         exit(1);
   	 }

	new_node->data = value;
	new_node->prev= NULL;
	new_node->next= NULL;

	return new_node;
}



void insert_at_end(struct node** phead, int value){
	struct node* new_node = create_node(value);

	if(*phead == NULL){ 
		*phead = new_node;
       	}

	struct node* temp= *phead;

	while(temp->next!=NULL)
	{
	   temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev= temp;
}


void display_forward(struct node * head){
	struct node* temp=head;

	while(temp!=NULL){
	printf(" %d -> ",temp->data);
	temp= temp->next;
	
	}
	printf("\n");



}

void display_backward(struct node * head){

	struct node* temp= head;

	while(temp->next!=NULL){
	     temp= temp->next;
	}

	while(temp!=NULL){
	   printf("%d->   ",temp->data);
	   temp = temp->prev;
	}
	printf("\n");

}




/////////////////////////////////////////////////////////////////////
int main(){

	struct node* head= NULL;

	insert_at_end(&head,30);
	insert_at_end(&head,40);

	printf("list (forward:::)::    ");
	display_forward(head);

	printf("list (backward:::)::    ");
	display_backward(head);







return 0;
}
