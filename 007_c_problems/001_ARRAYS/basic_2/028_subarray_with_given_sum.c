/*
 *
/////////////////////////////////////////////////////////////////////////////////////////////////////////
Find All Subarrays with a Given Sum

Problem: Identify all subarrays within an array that sum up to a specific target.
Example: For [1, 2, 3, 4] with a sum of 5, subarrays [2, 3] and [1, 4] qualify.
Hints: Use nested loops or a sliding window approach for optimizatio
/////////////////////////////////////////////////////////////////////////////////////////////////////////

 */
#include<stdio.h>




int main(){

	int arr[]={1,2,3,4,5,1,4};
	int n = sizeof(arr)/sizeof(arr[0]);

	int target =5;

	for(int i=0; i<n; i++){

	 int sum =0;
	 //-
	  for(int j=i; j<n; j++){
	    
		  sum+=arr[j];

		  if(sum == target){
		  
		  printf(" sub-array found: [");

		  for(int k=i; k<=j; k++){
		  
			  printf("%d ",arr[k]);
		  
		  }
		  printf("] \n");


		  }

		  
	  
	  
	  }
	  printf("\n");
	
	
	}

return 0;
}
