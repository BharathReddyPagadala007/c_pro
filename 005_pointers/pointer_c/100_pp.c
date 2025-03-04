#include<stdio.h>
#include<stdlib.h>


struct Node{

 int data;
 struct Node* next;

};

////////////////////////////
struct Node* create_node( int data)
{
 struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->next = NULL;

 return newNode;
}

////////////////////////////
void insert_at_begin(struct Node** phead, int data)

{
	 
         struct Node*   newNode =  create_node(data);
	 newNode->next = *phead;


	 *phead= newNode;


}

int main(){

	struct Node * head=NULL;


	insert_at_begin(&head,10);
	insert_at_begin(&head,20);

	struct Node* p = head->next;
	


	printf("head->data = %d,head->next = %p\n",head->data,head->next);
	printf("head->data = %d,head->next = %p\n",p->data,p->next);

return 0;
}
