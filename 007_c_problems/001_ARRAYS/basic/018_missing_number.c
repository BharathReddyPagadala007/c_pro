/*
 ///////////////////////////////////////
Find the Missing Number

Problem: Given an array of numbers from 1 to n, find the missing number.
Example: In [1, 2, 4, 5], the missing number is 3.
Hints: Calculate the sum of numbers from 1 to n and compare it with the sum of array elements.Find the Missing Number

Problem: Given an array of numbers from 1 to n, find the missing number.
Example: In [1, 2, 4, 5], the missing number is 3.
Hints: Calculate the sum of numbers from 1 to n and compare it with the sum of array elements.
*/
////////////////////////////////////////////
#include<stdio.h>

int main()
{

int arr[] = {1,2,4,5};
int sum = 5 * 3;
int n = 4;
int s=0;
int i;

for(i=0;i<n;i++)
{
 s = s +arr[i];

}


printf("%d mising\n",(sum -s));



return 0;
}
