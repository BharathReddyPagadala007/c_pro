#include<stdio.h>
#include<stdlib.h>


//struct Node
struct Node{
  int data;
  struct Node * next;
};

//////////////////////////////////////////////////
//
// CREATE A NODE
//  -- using malloc
//  -- give the members the initial values  data,next
//
//////////////////////////////////////////////////
// CREATE A LINKED LIST
// --INSERT
// --DELETE
//
//////////////////////////////////////////////////
//  OPERATIONS
//  ------------------------
//  INSERT
//  - BEGIN 
//  - END
//  - BETWEEN TWO NODES
//  - AT A POS
//  - AFTER A NODE
//  - BEFORE A NODE
//
//
//
//
//  DELETE
//  - begin
//  - end
//  - between two nodes
//  - at a pos
//  - after a node
//  - before a node
//
//
//
//  DISPLAY
//  - complete list from head to tail/end
//
//
//
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
//---------------------------------------
//void insert_between_nodes();
//---------------------------------------
void insert_at_pos(struct Node** phead, int data, int pos){

}
//---------------------------------------
void insert_after_node();
//---------------------------------------
void insert_before_node();
//---------------------------------------

//////////////////////////////////////////////////


void delete_at_begin();
void delete_at_end();
void delete_between_nodes();
void delete_at_pos();
void delete_after_node();
void delete_before_node();


//////////////////////////////////////////////////

void display_list();






//////////////////////////////////////////////////

int main()
{
  
struct Node* head = NULL;

	insert_at_end(&head,20);


	//insert_between_nodes(1,2,60);
	insert_at_end(&head,30);
	insert_at_end(&head,40);
	display_list();
	insert_at_begin(&head,10);
	display_list();
	delete_at_pos();
	display_list();
	delete_at_pos();
	insert_at_pos(&head,70,6);
	display_list();






return 0;
}
