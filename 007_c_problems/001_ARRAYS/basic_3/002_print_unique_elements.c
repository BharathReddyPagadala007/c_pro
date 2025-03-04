/*
Write a program in C to print all unique elements in an array.
*/
//////////////////////////////////////

#include<stdio.h>

int main()
{

 int arr[10]={1,2,3,4,5,6,7,5,8,2}; 
 int i,j;

 for(i=0;i<10;i++)
 {
   for(j=i+1;j<10;j++)
   {
	   if(arr[i]==arr[j])
	   {
	    
		   break;
	   }
   }
 }

return 0;
}
