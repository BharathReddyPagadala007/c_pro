#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};



void insert_at_end(struct Node** phead, int value){

  struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if(*phead == NULL){

     *phead = newNode;
     return ;
  }

  struct Node* temp = *phead;

  while(temp->next!= NULL){
     
	  temp = temp->next;
  }
  temp->next = newNode;


}

void display(struct Node** phead){
	struct Node* temp = *phead;

	if(temp == NULL){
	 printf("empty\n");
	 return;
	}

	while(temp!=NULL){
	
	printf("%d  -->",temp->data);
	temp = temp->next;
	}

 printf("NULL\n");


}
void delete_node(struct Node** phead, int target){

	struct Node* temp = *phead;
	struct Node* prev = NULL;

	while(temp!= NULL && temp->data!= target){
		prev= temp;
		temp= temp->next;
	}

	prev->next = temp->next;

	free(temp);





}
int main(){


	struct Node* head = NULL;

	insert_at_end(&head,10);
	insert_at_end(&head,11);
	insert_at_end(&head,12);
	insert_at_end(&head,13);
	insert_at_end(&head,14);
	insert_at_end(&head,15);

	display(&head);

	delete_node(&head,14);
	display(&head);

return 0;
}
