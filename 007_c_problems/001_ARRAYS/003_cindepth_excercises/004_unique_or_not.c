#include<stdio.h>

int main(){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int brr[] = {1,2,3,4,5,6,7,8,9,1};
	int al= sizeof(arr)/sizeof(arr[0]);
	int bl= sizeof(brr)/sizeof(brr[0]);
	int dup=0;

	for(int i=0; i<al;i++){
	
		for(int j=i+1; j<al;j++){
		
		  if(arr[i]==arr[j]){
		  dup=1;
		  }
		
		}
	
	}

	if(dup){
	printf("duplicate found\n");
	}else{
	printf("all elements are unique\n");
	}

	printf("---------------------\n");
	dup=0;
	for(int i=0; i<bl;i++){
	
		for(int j=i+1; j<bl;j++){
		
		  if(brr[i]==brr[j]){
		  dup=1;
		  }
		
		}
	
	}

	if(dup){
	printf("barr :: duplicate found\n");
	}else{
	printf("brr :: all elements are unique\n");
	}

return 0;
}
