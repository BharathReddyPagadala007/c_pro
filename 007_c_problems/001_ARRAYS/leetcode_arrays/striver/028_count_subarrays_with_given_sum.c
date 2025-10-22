/*
https://leetcode.com/problems/subarray-sum-equals-k/description
*/
 
#include<stdio.h>

int main(){

   int arr[] = {3, 1, 2, 4,1,1,1,3,-3,3,1,2,6,7};
   int n= sizeof(arr)/sizeof(arr[0]);

   for(int k=0; k<n; k++){
	   printf("%d  ",arr[k]);
   
   }
   printf("\n");



   int sum =0;
   int cnt=0;
   int k=3;


   for(int i=0; i<n; i++){

		   sum =0;

	   for(int j=i; j<n; j++){

		   //printf("%d  ",j);
		  sum+= arr[j];

		  if(sum == k){
			  cnt++;
			  printf("horray found one subarray with sum = k %d  at i-%d, j-%d\n",k,i,j);
		  
		  }
	   
	   
	   }
	   printf("\n-------------\n");
   
   
   }


   printf("count = %d\n",cnt);
return 0;
}
