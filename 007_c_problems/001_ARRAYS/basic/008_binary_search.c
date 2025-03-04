////////////////////////////////////////////////////////////
//        binary search
//
//        Binary Search
/*
Problem: Search for a value in a sorted array using a divide-and-conquer approach.
Example: In a sorted array [1, 3, 5, 7, 9], searching for 5 returns index 2.
Hints: Use pointers or indices to divide the search space in half repeatedly.
*/
///////////////////////////////////////////////////////////////
#include<stdio.h>

int main()
{
   int arr[]= {1,3,5,7,9,13,16,28,29,33,77,65,78,99,106,109};
   int n= sizeof(arr)/sizeof(arr[0]);
   int i,flag;

   printf("array size is %d\n",n);
   /*
   printf("check whether if the array is saorted otr not\n");

   for(i=0;i<n;i++)
   {
     if(arr[i]>arr[i+1])
     {
      int flag = 0;
     
     }

   }
   if(flag == 0)
   {
    printf("array is unsorted\n");
   
   }
   else
   {
   printf("array is sorted\n");
   
   }
   */

  //////////////////////////////////////////////////////////////////////////
  //
  //
  //  BINARY SEARCH
  //
  //
  //////////////////////////////////////////////////////////////////////////////////

int left,right,mid;
int target = 106;


left=0;
right=n -1;


while(left<=right)
{

	mid =left + (right - left )/2;

	
	if(arr[mid]== target)
	{
	
		printf("target is found at inex=%d-------->%d\n",mid,arr[mid]);
		return 0;
	}
	else if(arr[mid]<target)
	{
		left = mid +1;

	
	}
	else if(arr[mid]>target)
	{
		right =  mid -1;

	
	
	}







}














return 0;
}
