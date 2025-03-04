/*
 *
 *Merge Two Arrays

Problem: Combine two arrays into a single array.
Example: Merging [1, 3, 5] and [2, 4, 6] results in [1, 3, 5, 2, 4, 6].
Hints: Create a new array of size equal to the sum of both arrays and copy elements accordingly.
 *
 *
 *
 */
///////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>



int main()
{

	int arr[] ={1,3,5};
	int brr[] ={2,4,6};
	int i,j,k;
	int n1,n2,n3;

	 n1 =sizeof(arr)/sizeof(arr[0]);
	 n2 =sizeof(brr)/sizeof(brr[0]);
	

	n3 =n1+n2;
	int crr[n3];


	for(i=0;i<n1;i++)
	{
		crr[i]= arr[i];
	}
	for(j=0;j<n2;j++)
	{
		crr[i+j]= brr[j];

	}
	for(k=0;k<n3;k++)
	{
	  printf("%d\t",crr[k]);
	}
	printf("\n");





return 0;
}
