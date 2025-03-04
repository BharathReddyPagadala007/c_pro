/*
 Check if a String is a Palindrome
Write a function to check if a string is a palindrome (reads the same forward and backward).
Example:
Input: "radar"
Output: True
*/

//////////////////////
//  radar radar   palin
//  hello olleh   not a palin

#include<stdio.h>
#include<string.h>

int main()
{
	int i,j;
  char str[] = "radar";

  i=0;
  j=strlen(str)-1;
 int is_palindrome =1; 
  while(i<j)
  {
    if(str[i]!= str[j])
    {
	    is_palindrome =0;
    }
	    
 i++;
j--; 
  }
if(is_palindrome)
{
	printf("its a palindrome ");
}
else{

printf("nope");
}
return 0;
}
