/*
 *
Find the Majority Element

Problem: Find the element that appears more than half the time in an array, if such an element exists.
Example: In [3, 3, 4, 2, 3], the majority element is 3.
Hints: Use a frequency count or the Boyer-Moore Voting Algorithm.


n/2 

https://www.youtube.com/watch?v=n5QY3x_GNDg

*/

/////////////////////////////////////////////////////////////////////
// boyer moore voting algorithm
// // Step 1: Find a candidate
// // Step 2 : validate candidate
// // Step 3 : check is count > N/2 (condition : for majority elemenyt)
/////////////////////////////////////////////////////////////////////
#include<stdio.h>

int main()
{
  int arr[] ={5,5,5,3,5,5,2,5,3,5,2,5};
  int i,candidate;
  int count = 0;
  int n= sizeof(arr)/sizeof(arr[0]);
  //majority is 3 since its repeating thrice

  for(i=0;i<n;i++)
  {
	  if(count == 0)
	  {
	    candidate = arr[i];
	  }
	  else if (candidate = arr[i])
	  {
	   count++;
	  }
	  else
	  {
	  count --;
	  }

	  count =0;
	  for(i=0;i<n;i++)
	  {
	    if(candidate ==arr[i])
	    {
	    count++;
	    }
	  }


	  if(count> n/2)
	  {
	  printf("candidate exists and he is %d",candidate);
	  }
	  else
	  {
	  printf("no cand\n");
	  }
  }

return 0;
}
