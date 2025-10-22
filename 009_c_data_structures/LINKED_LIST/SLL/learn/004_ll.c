#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
};



///////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////

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
int main(){


	struct Node* head = NULL;

	insert_at_end(&head,10);
	insert_at_end(&head,11);
	insert_at_end(&head,12);
	insert_at_end(&head,13);
	insert_at_end(&head,14);
	insert_at_end(&head,15);

	display(&head);

	//delete_node(&head,10);

return 0;
}
