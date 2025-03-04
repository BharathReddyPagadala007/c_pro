/*
 * Delete an Element from a Specific Position

	Problem: Remove an element from a specified position in an array.
	Example: Deleting the element at index 1 in [1, 2, 3] results in [1, 3].
	Hints: Shift elements leftwards from the position of deletio
*/

////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>


int main()
{
  
  int arr[10] ={2,4,5,6,7,9};



  int index =2;   //arr[2]=10
  int pos =index;
//  int n= sizeof(arr)/sizeof(arr[0]); //wrong size of array
  int n =6;

  int i;
  

  for(i=index;i<n-1;i++)
  {
     arr[i]=arr[i+1];
  
  }
  n--;

  
//////////////////////////////////////////////////////
  for(i=0;i<n;i++){
  
  printf("%d\t",arr[i]);
  }

return 0;
}

