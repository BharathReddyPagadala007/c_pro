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
	int n = sizeof(arr)/sizeof(arr[0]);
	int min;
	min = arr[0];


	printf("sizeof of arr =%ld\n",sizeof(arr));  //sizeof is long unsigned int %ld
	for(i=0;i<n ;i++)
	{
	

	}
	printf("the smallest elemnt is %d\n",min);





return 0;
}
