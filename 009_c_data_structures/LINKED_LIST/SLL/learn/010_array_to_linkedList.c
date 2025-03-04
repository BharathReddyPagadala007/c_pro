
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};


struct Node* create_node(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}


struct Node* array_to_linkedlist(int arr[],int size){

	if(size == 0) return NULL;

	struct Node* head = create_node(arr[0]);
	struct Node* current = head;



	for(int i=1; i<size; i++){
		current->next = create_node(arr[i]);
		current = current->next;
	}

	return head;
}

void print_list(struct Node* head){
	struct Node* temp = head;

    while(temp!=NULL){
       printf("%d  -->",temp->data);
       temp=temp->next;
    }
    printf("NULL\n");
}

void free_list(struct Node* head){
	struct Node* temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(){
   struct Node* head = NULL;



    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);


    struct Node* p = array_to_linkedlist(arr,size);
    printf("print list\n");

    print_list(p);


    free_list(p);




return 0;
}
