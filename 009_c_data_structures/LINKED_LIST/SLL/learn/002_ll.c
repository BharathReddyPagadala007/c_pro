///////////////////////////////////////////////////////////////////////////
//
//   Write a function to count the number of occurrences of an element in a single linked list
//
///////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>


//struct Node
struct Node{
  int data;
  struct Node * next;
};


//////////////////////////////////////////////////

struct Node* create_node(int data){

  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

//////////////////////////////////////////////////


void insert_at_begin(struct Node** phead, int data){
	struct Node*  newNode = create_node(data);

	newNode->next = *phead; // head is  struct Node* 
				// phead is &head
				// *phead is struct Node*

	*phead = newNode;
	

}
//---------------------------------------
void insert_at_end(struct Node** phead, int data)
{
   
	struct Node* newNode = create_node(data);
	struct Node* p = *phead;

	while(p->next!=NULL)
	{
	  p = p->next;
	}

	p->next= newNode;


}


//////////////////////////////////////////////////


void display_list(struct Node** phead){
	int i;

	struct Node* p = *phead;

	while(p!=NULL)
	{
	 printf("%d\n",p->data);
	  p = p->next;
	
	}

}

//////////////////////////////////////////////////

/*
void countElement(struct Node** phead, int data)
{



}


*/



//////////////////////////////////////////////////

int main()
{
  
struct Node* head = NULL;

	insert_at_end(&head,20);
	insert_at_end(&head,30);
	insert_at_end(&head,20);
	insert_at_end(&head,40);
	insert_at_end(&head,20);
	insert_at_end(&head,20);
	insert_at_end(&head,20);
	insert_at_end(&head,40);
	insert_at_end(&head,20);
	insert_at_end(&head,40);
	insert_at_end(&head,20);
	insert_at_end(&head,40);
	display_list(&head);
	//countElement(&head,20);





return 0;
}
