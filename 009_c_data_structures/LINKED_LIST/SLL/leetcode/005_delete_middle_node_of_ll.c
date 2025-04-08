#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* create_node(int data){

	struct Node* newNode = malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = NULL;

	return newNode;

}

void insert_at_end(struct Node** phead, int data){

	struct Node* newNode = create_node(data);

	if(*phead == NULL){
	 *phead = newNode;
	 return; //vvimp
	}



	struct Node* p = *phead;

	while(p->next!= NULL){
		p = p->next;
	}

	p->next = newNode;

}

void display_list(struct Node* head){

	struct Node* p = head;
	while(p){
	
        printf("%d-> ",p->data);
	p = p->next; //vvimp otherwise list will not be traversed

	}
	printf("\n");


}
///////////////////////////////////////////////////////////////////////////////////

struct Node* middle_node(struct Node** phead){

	struct Node* slow = *phead;
	struct Node* fast = *phead;

	while(fast!= NULL && fast->next!=NULL){

		slow = slow->next;
		fast = fast->next->next;
	
	}


	return slow;

}
//------------------------------------------------------------------------------

struct Node* delete_middle_node(struct Node** phead){
//	if(*phead == NULL || *phead->next == NULL) return NULL;


	struct Node* prev= NULL;
	struct Node* slow = *phead;
	struct Node* fast = *phead;

	while(fast!=NULL && fast->next!=NULL){
	
		prev= slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	if(prev!=NULL){
	  prev->next = slow->next;
	
	}

	free(slow);



return *phead;
}




///////////////////////////////////////////////////////////////////////////////////

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
	display_list(head);

	printf("-------------------------------\nlist from middle node (if there are two second of it:\n)");
	display_list(middle_node(&head));

	printf("\n===============================================\n");
	printf("delete middle node of linkedlist: \n");

	display_list(delete_middle_node(&head));




return 0;
}
