#include<stdio.h>
#include<stdlib.h>

///////////////////////////////////////////////////////
 struct Node{
 	int data;
	struct Node* next;
 };

///////////////////////////////////////////////////////













///////////////////////////////////////////////////////

struct Node*  create_node(int data){

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));


  newNode->data = data;
  newNode->next = NULL;


return newNode;
}

///////////////////////////////////////////////////////

void insert_at_end(struct Node** phead, int data)
{
	struct Node* newNode = create_node(data);
	if(*phead == NULL){
	*phead = newNode;
	return;
	}
	struct Node* p = *phead;



	while(p->next!=NULL){
	p = p->next;
	
	}

	p->next = newNode;

}


///////////////////////////////////////////////////////
void display_list(struct Node** phead)
{

	struct Node* p = *phead;

	while(p!=NULL){
		printf("%d\n",p->data);
		p= p->next;
	}
	printf("---------------\n");
}
//------------------------------------------------------------------
void display_from_to(struct Node** phead,int left, int right)                                                                                                   {                                                                                                                                                               
                                                                                                                                                                
	printf("print from %d to %d\n",left,right);
        struct Node* p = *phead;                                                                                                                                

	int l=0,r=0;
	while(l<left){
		p =p->next;
		l++;
		r++;
	
	}
                                                                                                                                                                
        while(p!=NULL && r<=right){                                                                                                                                         
                printf("%d--%dth elem\n",p->data,r);                                                                                                                         
                p= p->next;                                                                                                                                     
		r++;
        }                                                                                                                                                       
        printf("---------------\n");                                                                                                                            
}                                                                                                                                                               
                                                                                                                                                                
   

///////////////////////////////////////////////////////
//

struct Node* reverse(struct Node** phead){

	struct Node* prev = NULL;
	struct Node* curr = *phead;
	struct Node* next = NULL;

	while(curr!= NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}

	return prev;
}

struct Node* reverse_left_right(struct Node** phead, ){



}

///////////////////////////////////////////////////////
int main(){

	struct Node* head = NULL;

	insert_at_end(&head,10);
	insert_at_end(&head,11);
	insert_at_end(&head,12);
	insert_at_end(&head,13);
	insert_at_end(&head,14);
	insert_at_end(&head,15);
	insert_at_end(&head,16);
	insert_at_end(&head,17);
	insert_at_end(&head,18);
	insert_at_end(&head,19);
	insert_at_end(&head,20);

	display_list(&head);
	head= reverse(&head);
	display_list(&head);

	display_from_to(&head,2,6);
	

return 0;
}

///////////////////////////////////////////////////////
