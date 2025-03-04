//////////////////////////////////////////
/*
Move All Zeroes to the End

Problem: Given an array, move all zeroes to the end while maintaining the relative order of non-zero elements.
Example: [0, 1, 0, 3, 12] becomes [1, 3, 12, 0, 0].
Hints: Traverse the array and shift non-zero elements forward.
*/
//////////////////////////////////////////
#include<stdio.h>

int main()
{

	int i;
int arr[]={0,1,0,3,12};
int n =sizeof(arr)/sizeof(arr[0]);

// is shifting costly than storing in other array?

int nonzeroIndex=0;


for(i=0;i<n;i++)
{
   if(arr[i]!=0)
   {
   arr[nonzeroIndex++]= arr[i];
   }
}
for(i=nonzeroIndex;i<n;i++)
{
  arr[i]=0;
}





for(i=0;i<n;i++)
{
  printf("%d\t",arr[i]);

}

printf("\n");
return 0;
}
