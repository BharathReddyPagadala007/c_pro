/*
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 * Average of Elements

Problem: Find the average value of the elements in an array.
Example: For [10, 20, 30, 40], the average is (10 + 20 + 30 + 40) / 4 = 25.
Hints: First calculate the sum, then divide by the number of elements.
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
	printf("the avg =  %d\n",sum / arr_size);





return 0;
}
