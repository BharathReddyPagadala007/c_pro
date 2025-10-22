#include<stdio.h>


int main(){

	int arr[] = {2,10,30,50,55,60,63,67,97};
	int n = sizeof(arr)/sizeof(arr[0]);


	int low, mid,high;
	//int k=63;
	int k=99;


	low=0;
	high= n-1;

	while(low<=high){
		mid = low+ (high -low)/2;
	 
		if(arr[mid]== k)
		{
			printf("found k at %d\n",mid);
		return mid;
		
		}else if(arr[mid]>k){
		high = mid-1;
		
		
		}else{
		
			low =mid+1;
		
		
		}
	
	
	}
	printf("not found\n");

return 0;
}
