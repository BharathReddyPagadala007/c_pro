/*
////////////////////////////////////////////////////////////////////////
Find the Median of an Array

Problem: Calculate the median value of a sorted array.
Example: For [1, 3, 4, 8, 9], the median is 4. For [1, 2, 3, 4], it’s the average of 2 and 3 (2.5).
Hints: Sort the array if it’s not already sorted, then find the middle element(s).
////////////////////////////////////////////////////////////////////////
*/
////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>


int main()
{

int arr[]={1,3,4,8,9};
int i;
int n = sizeof(arr)/sizeof(arr[0]);
//sort;
//assume its sorted
if(n%2 !=0)
{

printf("median is %d \n",arr[n/2]);
}
else
{
printf("median is %f \n",(arr[(n-1)/2]+ arr[(n+1)/2] )/2.0);
}
for(i=0;i<n;i++)
{
  printf("%d\n",arr[i]);

}


return 0;
}
