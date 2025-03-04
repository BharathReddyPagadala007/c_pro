/*
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 * Sum of Elements

Problem: Calculate the sum of all the elements in an array.
Example: For [2, 4, 6, 8], the sum is 20.
Hints: Use a loop to add each element to a running total.
 * /////////////////////////////////////////////////////////////////////////////////////////////
*/



#include<stdio.h>

int main()
{
	int arr[] = {2,8,4,10,12,20,27,0,-12};
	int i;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int sum=0; //needs to be initialised 


	for(i=0;i<arr_size;i++)
	{

		sum += arr[i];
	}
	printf("the sum =  %d\n",sum);





return 0;
}
