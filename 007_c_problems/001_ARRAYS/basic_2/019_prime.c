/*
Find All Prime Numbers in an Array

Problem: Identify and list all the prime numbers in a given array.
Example: For [10, 11, 15, 17, 18], the prime numbers are 11 and 17.
Hints: Implement a function to check if a number is prime, then filter the array using this function.
*/
////////////////////////////////////////////////////////////////////


#include<stdio.h>


int main()
{
  int arr[]={10,11,15,17,18}; 
  int n =5;

int i,j,count;

  //if a number is prime it will have no divisors except 1 and itself 
  //  lets a num % i ==0 only whem i ==0 or n
  for(i=0;i<n;i++)
  {
	  count =0;
	  for(j=1;j<arr[i];j++)
	  {
		if(arr[i]%j==0)
		{
		count ++;
		}	
	  }
	  if(count<3)
	  {
	  printf("%d is a prime\n",arr[i]);
	  }
  }
return 0;
}
