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

	
	int current_sum=0;
	int start=0;
	
	for(int i=0; i<n; i++){
	 printf("%d  ",arr[i]);
	
	}
	printf("\n");
	
	for(int end=0; end<n; end++){
	
		current_sum+=arr[end];

		while(current_sum > target && start<=end ){
		
			current_sum-=arr[start];
			start++;
		
		}

		if(current_sum == target){
		
			printf("subarray found start at  %d,ending at  %d",start,end);
			printf("\n");

			for(int k=start; k<=end; k++){
			
				printf("%d  ",arr[k]);
			
			}
			printf("\n");
		
		
		}

	
	
	}

return 0;
}
