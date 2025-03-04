/////////////////////////////////////////////////////////////////
/*
Find the Second Largest Element

Problem: Write a program that finds the second largest unique element in an array.
Example: For [7, 2, 8, 3, 8], the second largest is 7.
Hints: First find the largest element, then search for the largest element that is not equal to it.
*/

/////////////////////////////////////////////////////////////////


#include<stdio.h>


int main()
{

  int arr[] = {7,2,8,3,8,9};
  int n = sizeof(arr)/sizeof(arr[0]);


  int i;
  int max,sec;
  max =arr[0];
  sec =arr[0];

  for(i=0;i<n;i++)
  {
	 if(arr[i]>max)
	 {
		 max= arr[i];
	 } 

  
  }

  for(i=0;i<n;i++)
  {
	 if(arr[i]< max && arr[i]> sec)
	 {
	 sec =arr[i];
	 }
  }

  printf("\nmax=%d  sec max=%d\n",max,sec);










return 0;
}
