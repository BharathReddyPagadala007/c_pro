#include<stdio.h>

int main(){

	int arr[]= {20,40,50,60,30,80};
	int len = sizeof(arr)/sizeof(arr[0]);

	int temp;
	int i,j;

	for(int i=0; i<len; i++){
	
		printf("%d ",arr[i]);
	}
	printf("\n");

	int n;
	printf("number of elements to be reversed: \n");
	scanf("%d",&n);

	for( i=0,j=n-1; i<j; i++,j--){
	
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]= temp;

	}
	printf("\n");

	for(int i=0; i<len; i++){
	
		printf("%d ",arr[i]);
	}
	printf("\n");

return 0;
}
