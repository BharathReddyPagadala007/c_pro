/*
Check if an Array is a Palindrome

Problem: Determine if an array reads the same forward and backward.
Example: [1, 2, 3, 2, 1] is a palindrome.
Hints: Compare elements from the start and end, moving toward the center.
*/

#include<stdio.h>

int main()
{
int arr[] ={2,1,2,3,2,1};
int n= sizeof(arr)/sizeof(arr[0]);

int i,j,is_palindrome=1;

for(i=0,j=n-1;i<j;i++,j--)
{
   if(arr[i]!=arr[j])
   {
    
     is_palindrome =0;  
   }

}
if(is_palindrome ==1)
{
printf("yes its palindrome\n");

}
else{
printf("no man\n");

}



return 0;
}
