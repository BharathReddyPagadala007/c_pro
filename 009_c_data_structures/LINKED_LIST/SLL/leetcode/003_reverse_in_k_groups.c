#include<stdio.h>
#include<stdlib.h>

struct Node{

	int data;
	struct Node* next;

};

////////////////////////////////////////////////////
struct Node* create_node(int data){

	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;

return newNode;
}

////////////////////////////////////////////////////

void insert_at_end(struct Node** phead, int data){

	struct Node*  newNode = create_node(data);
	if(*phead== NULL){
		*phead = newNode;
		return;
	
	}


	struct Node* p = *phead;

	while(p->next!=NULL){    // this should stop at last element 
	p = p->next;
	}

	p->next = newNode;

}

///////////////////////////////////////////////////////////////
//


void display_list(struct Node** phead){

	struct Node* p = *phead;

	while(p!=NULL){
		printf("%d-> ",p->data);
		p = p->next;
	
	}
	printf("\n");


}

///////////////////////////////////////////////////////////////


int  get_length(struct Node* head){

	int len=0;

	while(head){
	len++;
	head= head->next;
	}
printf("length of linkedlist = %d\n",len);
return len;
}


///////////////////////////////////////////////////////////////
struct Node* reverse_k_group(struct Node** phead, int k){
	if(*phead== NULL || k==1) return *phead;


	struct Node dummy;
	dummy.next = *phead;
	struct Node* prevGroupEnd = &dummy;
	struct Node* curr          = *phead;
	int totalNodes 		   = get_length(*phead);


	while(totalNodes>=k){

		struct Node* groupStart = curr;
		struct Node* prev = NULL;
		struct Node* next = NULL;


		for(int i=0; i<k; i++){
			next = curr->next;
			curr->next= prev;
			prev = curr;
			curr = next;
		}

		//connect previous group to new head

		prevGroupEnd ->next = prev;
		groupStart ->next = curr;

		//move prevGroupEnd to end of newGroup

		prevGroupEnd = groupStart;

	  	totalNodes-=k;
		curr = prevGroupEnd->next; 
	}


	*phead = dummy.next; // this is mandatory

return dummy.next;

}

///////////////////////////////////////////////////////////////

int main(){

	struct Node* head = NULL;
	insert_at_end(&head,10);
	insert_at_end(&head,20);
	insert_at_end(&head,30);
	insert_at_end(&head,40);
	insert_at_end(&head,50);
	insert_at_end(&head,60);
	insert_at_end(&head,70);
	insert_at_end(&head,80);
	insert_at_end(&head,90);
	insert_at_end(&head,100);
	display_list(&head);

	reverse_k_group(&head,3);
	display_list(&head);




return 0;
}
/////////////////////////////////////////////////////////////
