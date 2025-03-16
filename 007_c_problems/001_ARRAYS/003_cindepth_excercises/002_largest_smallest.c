#include<stdio.h>


int main(){

	int arr[]= {1,2,3,4,5,6,7,8,9,10,101,20,30,700};
	int len=sizeof(arr)/sizeof(arr[0]);
	int max,min;
	max= min=arr[0];

	for(int i=1; i<len; i++){

	
		if(arr[i]>max){
		max = arr[i];
		}else if(arr[i]<min){
		min = arr[i];
		}


	
	}
	printf("max= %d, min= %d\n",max,min);
	printf("\n");

return 0;
}
