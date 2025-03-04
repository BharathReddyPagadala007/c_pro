
/*
 Write a program in C to find the missing number in a given array. There are no duplicates in 
 */
//
// array should start with zero
//
////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>


int main()
{





   int nums[] = {0,1,2,3,4,6,7,8,9};
   int numsSize= sizeof(nums)/sizeof(nums[0]);



   
    int x_full =0;
    int x_nums = nums[0];
    int i;

    for(i=1;i<=numsSize; i++)
    {
     x_full = x_full ^ i;
    }

    for(i=1;i<numsSize;i++)
    {
      x_nums =  x_nums ^ nums[i];
    }


    printf("  %d is missing \n",x_full ^ x_nums);


    return 0;



}
