/*
 *
 * /////////////////////////////////////////////////////////////////////////////////////////////
 * Array Reversal

Problem: Reverse the order of elements in an array.
Example: An array [1, 2, 3, 4, 5] should become [5, 4, 3, 2, 1].
Hints: Swap elements starting from the ends of the array and work towards the middle.
 * /////////////////////////////////////////////////////////////////////////////////////////////
*/



#include<stdio.h>

void swap(int* , int*);
int main()
{
	int arr[] = {2,8,4,10,12,20,27,0,-12};
	int i;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int temp;


	for(i=0;i<arr_size/2;i++)
	{
	
	//	temp = arr[i];
	//	arr[i] = arr[arr_size -i -1];
	//	arr[arr_size -i -1]= temp;



		swap(&arr[i],&arr[arr_size - 1 - i]);
	}


	for(i=0;i<arr_size;i++)
	{
          printf("%d\t",arr[i]);	
	}



return 0;
}
void  swap(int * a, int * b)
{

  int temp =*b;
  *b =*a;
  *a= temp;


}
