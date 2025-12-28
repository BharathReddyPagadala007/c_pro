//what is the output of the program

#include<stdio.h>


int main(){

	struct Node{
	int a;
	int b;
	};



	struct Node* ptr = NULL;
	printf("ptr = %d\n",ptr);
//	printf("*ptr = %d\n",*ptr);
	printf("ptr->a = %d\n",ptr->a);


	if(ptr && ptr->a){  // ptr->a  seg fault
	
		ptr->a = 2;

	printf("ptr = %d\n",ptr);
//	printf("*ptr = %d\n",*ptr);
	printf("ptr->a = %d\n",ptr->a);
		
	
	}

	printf("reached outside the loop\n");
return 0;
}
