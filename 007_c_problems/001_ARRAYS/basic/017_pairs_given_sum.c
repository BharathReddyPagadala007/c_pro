/*
 * Find Pairs with a Given Sum

Problem: Find all pairs of elements in an array that add up to a specific target value.
Example: In the array [1, 2, 3, 4], the pairs (1, 3) and (2, 2) add up to 4.
Hints: Use a nested loop or a hash table for efficient lookups.
*/
///////////////////////////////////////////////////////////////////

#include<stdio.h>

int main()
{
 int i,j,k;
int arr[]={1,2,3,4,5,6,7,8,9,0}; 
int n=10;

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)// j= i, i+1, 0 
    {
       if(arr[i] + arr[j] == 6)
       {
       printf("(%d  %d)\n",arr[i],arr[j]);
       }

    
    }

}


return 0;
}
