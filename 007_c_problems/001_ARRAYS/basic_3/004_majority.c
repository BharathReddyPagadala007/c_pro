/*
 Write a program in C to find the majority element of an array.
(A majority element in an array A[] of size n is an element that appears more than n/2 times 
(and hence there is at most one such element).
*/
////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>


int main()
{
	int arr[] ={5,2,5,5,1,2,5,5,5,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int count =0;

	int i,j;

	int candidate;

	for(i=0;i<n;i++)
	{
	    if(count== 0)
	    {
	      candidate = arr[i];
	    }
	    else if(candidate == arr[i])
	    {
	    count ++;
	    }
	    else
	    {
	    count--;
	    }
	}

	    count =0;
	    for(i=0;i<n;i++)
	    	if(arr[i]== candidate)
	     		 count++;

	    if(count >n/2)
	    {
	     printf("candidate = %d\n",candidate);

	    }
	    else
	    {
	    printf("candidate not found \n");
	    }
	

return 0;
}
