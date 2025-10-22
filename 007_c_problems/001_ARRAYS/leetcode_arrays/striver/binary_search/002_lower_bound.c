/*
The lower bound of a key in a sorted array is the index of the first element that is greater than or equal to the given key. If the key is present, it returns the first occurrence of that key. If the key is not present, it returns the index where the key can be inserted while maintaining the sorted order.
*/


/////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>


int lower_bound(int arr[],int n,int key){

	int low =0, high = n;
	int mid;

	while(low < high){
		mid = low + (high - low)/2;

		if(arr[mid]>= key){
		// move left 
		  high = mid;
		}else{
	 	  // move right
	         low = mid+1;
		}
	
	
	
	}


	return low;
}
int upper_bound(int arr[],int n, int key){

	int low =0, high =n;
	int mid;
	while(low < high){
		mid = low + (high - low)/2;

		if(arr[mid]>key){
		
		// move right
		high = mid;
		
		}else{
		
		// move left
		low = mid +1;
		
		}
	
	
	
	}

return high;


}

/////////////////////////////////////////////////////////

int main(){

	    int arr[] = {1, 2, 4, 4,4,4,4,4,4,5, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int index = lower_bound(arr, n, key);
    printf("Lower bound of %d is at index %d\n", key, index);
    int index2 = upper_bound(arr, n, key);
    printf("upper bound of %d is at index %d\n", key, index2);

return 0;
}
