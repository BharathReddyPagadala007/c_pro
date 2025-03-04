///////////////////////////////////////////////////////////////////////////////
/*
 * Array Sorting

Problem: Implement a sorting algorithm to arrange the elements in ascending or descending order.
Example: [4, 2, 9, 1] sorted in ascending order becomes [1, 2, 4, 9].
Hints: Start with simple algorithms like Bubble Sort, Selection Sort, or Insertion Sort.
*/
/////////////////////////////////////////////////////////////////////////////
/*
 * Insertion sort is a simple and intuitive sorting algorithm that works similarly to the way people sort playing cards in their hands. It builds the sorted array (or list) one element at a time by repeatedly picking the next unsorted element and inserting it into its correct position among the already sorted elements. Here’s how it works step by step:
   - Insert 3 in its position: `[1, 2, 3, 4, 5, 6]`
   */
//////////////////////////////////////////////////////////////////////////////////////
//
//
//      INSERTION SORT
//
//
///////////////////////////////////////////////////////////////////////
#include<stdio.h>

int main()
{

	int arr[] ={3,5,6,2,8,7,4,9,1};
	int i,j,key;
	int n=9;

	for(i=1;i<n;i++)
	{
	 key = arr[i];
	 j=i-1;

	 while(j>=0 && arr[j]>key)
	 {
		 arr[j+1]= arr[j];
		 j= j-1;
	 }
	 arr[j+1]= key;
	
	}
	for(i=0;i<9;i++)
	printf("%d\t",arr[i]);

return 0;
}
