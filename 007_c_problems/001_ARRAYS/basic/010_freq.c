/*
 * Count Frequency of Elements

Problem: Count how many times each unique element appears in an array.
Example: For [1, 2, 2, 3, 3, 3], the output would be 1 occurs 1 time, 2 occurs 2 times, 3 occurs 3 times.
Hints: Use a separate array or hash table to keep track of counts.
*/


#include<stdio.h>
#define MAX 10


int main()
{
	int arr[] ={1,2,2,3,3,1,1,1,1,1,1,1,1,1,1,3,3,3,3,4,3,6,7,6};

	int n =sizeof(arr)/sizeof(arr[0]);
	int count[MAX]={0};

	int i,j,k,max_value;
	max_value= arr[0];
	for(i=0;i<n;i++)
	{
	
		if(arr[i]>max_value)
		{
			max_value=arr[i];
		}
	
	}

	for(i=0;i<n;i++)
	{
	
		count[arr[i]]++;

	}
	

	for(i=0;i<max_value;i++)
	{
	 printf("%d--->%d  :times\n",i,count[i]);
	}





return 0;
}
