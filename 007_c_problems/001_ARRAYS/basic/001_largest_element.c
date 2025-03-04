/*
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 *  Find the Largest Element

	Problem: Write a program that takes an array of integers as input and finds the largest element.
	Example: For an array [2, 8, 4, 10, 3], the largest element is 10.
	Hints: Use a loop to traverse the array and keep track of the maximum value encountered.
 * /////////////////////////////////////////////////////////////////////////////////////////////
*/



#include<stdio.h>

int main()
{
	int arr[] = {2,8,4,10,12,20,27};
	int i;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int max;
	max = arr[0];


	printf("sizeof of arr =%ld\n",sizeof(arr));  //sizeof is long unsigned int %ld
	for(i=0;i<arr_size;i++)
	{
	
	//	printf("%d\n",arr[i]);
	
		if(arr[i]>max)
		{
		max= arr[i];
		}

	}
	printf("the largest elemnt is %d\n",max);





return 0;
}
