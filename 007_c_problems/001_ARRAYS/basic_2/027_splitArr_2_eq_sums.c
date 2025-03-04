/*
Split an Array into Two Equal Sums

Problem: Check if an array can be split into two subarrays with equal sums.
Hints: Use a running sum to check for possible split points.
*/


//////////////////////////////////////////////////////////////////////////////
//
//    split an array into equal sums
//
//    the sum should be divisible by 2
//
//    here we are not finding all possible combinations just splitting based on running sum
//
//    leftTotal  == rightTotal == Total / 2
//
//
//
////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

int main()
{
	int leftSum=0,total=0;
	int arr[]={1,2,3,6};
	int n=4;
	int i;

	for(i=0;i<n;i++)
	{
	  total += arr[i];
	}
	printf("%d==total\n",total);

	if(total %2 !=0)
	{
	printf("cant be split");
	return 0;
	}

	//////////////////////////////////////////////////////////////////
	for(i=0;i<n;i++)
	{
		leftSum+=arr[i];
 
	if(leftSum == total /2 )
	{
	printf("can be split");
	return 0;
	}
	}
	///////////////////////////////
	  printf("The array can't be split into two equal sum subarrays.\n");


return 0;
}
