#include<stdio.h>
#include<stdlib.h>


///////////////////////////////////
//  node contains dat and a link to itself  selreferntial structure .. will write a typedef too bu
struct node{
	int data;
	struct node* next;
};

///////////////////////////////////
////////////operations/////////////////
//creation 
struct node* create_node(int value){

	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL;

	return new_node;
}


void append_node(struct node** phead, int value){
	
	struct node* new_node = create_node(value);
	if(*phead == NULL){
	*phead = new_node;
	return ;
	}
	
	struct node* temp = *phead;
	while(temp->next!=NULL){
		temp = temp ->next;
	}
	temp->next = new_node;
}

void print_list(struct node* head){
	int pos=1;
	if(head== NULL){
		printf("list is empty");
	}else{
		struct node* temp= head;
	while(temp!= NULL){
		printf("%d[%d]-->",temp->data,pos);
		temp = temp ->next;
		pos++;
	}
	printf("\n");
	}
}

void insert_at_begin(struct node** phead, int value){
  
	struct node* new_node = create_node(value);

	new_node->next = *phead;
	*phead = new_node;
}

void insert_at_pos(struct node** phead, int value, int pos){
	
	struct node* new_node = create_node(value);
	if(pos==0){
	 *phead = new_node;
	 return ;
	}
	struct node* temp;
	temp = *phead;
	int i;
	for(i=1;  i<pos-1 && temp!=NULL; i++){
		temp = temp->next;
	}
	if(temp == NULL){
	 printf("out of bounds\n");
	}
	new_node->next =  temp->next;
	temp->next= new_node;
}


void delete_by_value(struct node** phead, int value){

 struct node* temp = *phead;
 struct node* prev = NULL;

 int pos=1;

 if(temp!=NULL && temp->data==value){
	 
	 *phead= temp->next;
	 free(temp);
	 return;
 }

 while(temp!=NULL && temp->data!=value){
	 prev= temp;
	 temp= temp->next;
	 pos++;
 }
 if(temp==NULL){
  
	 printf("there is no such value \n");
 }

 prev->next= temp->next;
 free(temp);
 printf("deleted value -->%d   {pos==%d}\n",value,pos );
 return ;
}

void reverse_list(struct node** phead){

	
	struct node* prev=  NULL;
	struct node* curr= *phead;
	struct node* next=  NULL;

	while(curr!=NULL){
	
		next=curr->next;
		curr->next= prev;
		prev= curr;
		curr=next;
	} 	
	*phead = prev;

	//learn recursive approach
}


int detect_loop(struct node* head){



}

///////////////////////////////////
int main()
{

  struct node * head=NULL;

  append_node(&head, 10);
  append_node(&head, 20);
  append_node(&head, 30);
  append_node(&head, 40);
  append_node(&head, 50);

  ////////////////////////
    printf("Original List: ");
    print_list(head);
  ////////////////////////

    printf("modified  List: ");
  insert_at_begin(&head,5);
  insert_at_begin(&head,3);
  print_list(head);
  ////////////////////////
  
  insert_at_pos(&head,25,7);
    printf("modified  List: ");
  print_list(head);
  ////////////////////////
  delete_by_value(&head,25);
  printf("after deleting 25\n");
  print_list(head);
  ////////////////////////
  //reverse
  reverse_list(&head);
  printf("reversed list  --\n");
  print_list(head);
  ////////////////////////
  detect_loop(head);
  printf("detect if theres is a loop \n");
  print_list(head);

return 0;
}

