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


void insert_at_begin(struct node** phead, int value){

	struct node* new_node = create_node(value);

	if(*phead == NULL){
		*phead= new_node;
		return;
	}

		new_node->next= *phead;
		(*phead)->prev=new_node;
		*phead= new_node;
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

void delete_node(struct node** phead, int key){

	if(*phead == NULL){
		printf("listis empty\n");
		return ;
	}

	struct node* temp  = *phead;

	while(temp!=NULL && temp->data!=key){
		temp =temp->next;
	}

	if(temp == NULL){
		printf("key %d not found bye bye \n",key);
		return;

	}
	
	if(temp->prev == NULL){
		*phead = temp->next;
		if(temp->next!=NULL){
			temp->next->prev = NULL;
		}
	}else{
	  
		temp->prev->next = temp->next;
		if(temp->next!= NULL){
		temp->next->prev = temp->prev;
		}
	
	
	}

}



/////////////////////////////////////////////////////////////////////
int main(){

	struct node* head= NULL;

	insert_at_begin(&head,20);
	insert_at_begin(&head,10);
	insert_at_end(&head,30);
	insert_at_end(&head,40);

	printf("list (forward:::)::    ");
	display_forward(head);

	printf("list (backward:::)::    ");
	display_backward(head);


	delete_node(&head, 20);
	printf("after deteting 20 ==>>list (forward:::)::    ");
	display_forward(head);





return 0;
}
