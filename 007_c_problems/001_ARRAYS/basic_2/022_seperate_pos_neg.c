/*
 //////////////////////////////////////////////////////////////
Rearrange Positive and Negative Numbers Alternately

Problem: Rearrange an array so that positive and negative numbers alternate, preserving the order within each group.
Example: For [3, -2, 5, -7, 8], one possible rearrangement is [3, -2, 5, -7, 8].
Hints: Partition the array into positives and negatives, then merge them back alternately.
 //////////////////////////////////////////////////////////////
*/

#include<stdio.h>

int main()
{
  int arr[]={3,-2,5,-7,8};
  int n =sizeof(arr)/sizeof(arr[0]);
  int pos[n],neg[n];
  int i;
  int pcount=0,ncount=0;


  for(i=0;i<n;i++)
  {
   printf("%d ",arr[i]);
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
	  if(arr[i]>0)
	  {
	  pos[pcount++]=arr[i];
	  }
	  else{
	  neg[ncount++]=arr[i];
	  }
  }
  printf("\n");
  int p=0,c=0;
  for(i=0;i<n;i++)
  {
	  if(i%2 ==0 && p< pcount)
	  {
		  arr[i]=pos[p++];
	  }
	  else
	  {
	  	arr[i]=neg[c++];
	  }
  }
  printf("\n");
  for(i=0;i<n;i++)
  {
   printf("%d ",arr[i]);
  }
  printf("\n");
return 0;
}
