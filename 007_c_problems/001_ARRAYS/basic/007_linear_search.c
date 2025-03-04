/*
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 * Linear Search

Problem: Search for a specified value in an array and return its index if found, otherwise indicate that it is not present.
Example: Searching for 7 in [5, 7, 1, 8] returns index 1.
Hints: Loop through each element and compare it with the target value.
 * /////////////////////////////////////////////////////////////////////////////////////////////
*/



#include<stdio.h>

int main()
{
	int arr[] = {2,8,4,10,12,20,27,0,-12};
	int i;
	int n = sizeof(arr)/sizeof(arr[0]);
	int min;
	min = arr[0];


	printf("sizeof of arr =%ld\n",sizeof(arr));  //sizeof is long unsigned int %ld
	for(i=0;i<n ;i++)
	{
		if(arr[i]==10)
		{
		printf("10 is found at --->%d\n",i);
		}
	

	}





return 0;
}
