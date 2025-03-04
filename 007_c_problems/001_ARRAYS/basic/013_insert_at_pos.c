
/*
Insert an Element at a Specific Position

Problem: Add an element to an array at a given index, shifting the other elements as needed.
Example: Inserting 10 at index 2 in [1, 2, 3, 4] results in [1, 2, 10, 3, 4].
Hints: Make room by shifting elements from the specified index onwards.
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
  

  for(i=n;i>index;i--)
  {
  arr[i]=arr[i-1];
  
  }
  n++;
  arr[pos]= 10;


  for(i=0;i<n;i++){
  
  printf("%d\t",arr[i]);
  }

return 0;
}

