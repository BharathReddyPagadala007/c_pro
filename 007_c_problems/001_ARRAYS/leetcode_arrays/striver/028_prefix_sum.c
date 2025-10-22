/*
https://leetcode.com/problems/subarray-sum-equals-k/description
*/
 

// count number of subarrays with given sum k
// using prefix sum subarray metthod

#include<stdio.h>

int main(){

   int arr[] = {3, 1, 2, 4,1,1,1,3,-3,3,1,2,6,7};
   int n= sizeof(arr)/sizeof(arr[0]);

   for(int k=0; k<n; k++){
	   printf("%d  ",arr[k]);
   
   }
   printf(" \n");



   int sum =0;
   int cnt=0;
   int k=3;
   
   //int prefix[n]={0};   variable size array object  cannot be initialised
   
   int prefix[n];

   prefix[0]=arr[0];

   for(int z=1; z<n;z++){
	   prefix[z]=0;
   
   }
   printf("prefix array : \n%d  ",prefix[0]);
   for(int p=1; p<n; p++){

	   prefix[p] = arr[p]+prefix[p-1];
	   printf("%d  ",prefix[p]);
   
   }
   printf("\n-----\n");
   

   for(int i=0; i<n; i++){
	   for(int j=i; j<n; j++){
		   sum = (i==0)? prefix[j] : prefix[j]-prefix[i-1];
		   if(sum ==k ){
			  cnt++ ;
		     printf("\n");
		   }
	   }
   
   }

printf("count = %d\n",cnt);

return 0;
}
