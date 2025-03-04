/*
   ///////////////////////////////////////////
Array Rotation Using Reversal Algorithm

Problem: Rotate an array to the left by d positions using the reversal algorithm.
Example: Rotating [1, 2, 3, 4, 5] by 2 positions results in [3, 4, 5, 1, 2].
Hints: Reverse segments of the array and then the entire array.
*/
   ///////////////////////////////////////////

//the above example is left rotation

#include<stdio.h>
void reverse(int arr[], int start, int end)
{
	int temp;
  while(start < end)
  {
    temp = arr[start];
    arr[start]=arr[end];
    arr[start]= temp;
    start++;
    end--;
  }

}
int main()
{

  int arr[]={1,2,3,4,5};
  int n=5;
  int i;

  ////////////////
  reverse(arr,0,4);
  reverse(arr,0,2);
  reverse(arr,3,4);

for(i=0;i<5;i++)
  printf("%d\t",arr[i]);
return 0;
}
