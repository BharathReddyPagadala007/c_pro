#include<stdio.h>

int main(){

	int arr[]= {20,40,50,60,30,80};
	int len = sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<len; i++){
	
		printf("%d ",arr[i]);
	}
	printf("\n");

return 0;
}
