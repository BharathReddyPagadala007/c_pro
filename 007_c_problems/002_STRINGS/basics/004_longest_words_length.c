/*
Find the Length of the Longest Word in a String
Write a function to find the length of the longest word in a given string.
Example:
Input: "Embedded programming is fun"
Output: Length of longest word: 12
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>



int main()
{
	////dec
char * str = "Embedded programming is fun";
int currlen=0,maxlen=0;



while(*str)
{
   if(isalpha(*str))
   {
     currlen++;
     
   }
   else
   {
    if(currlen> maxlen)
	   {
	      maxlen = currlen;
	   }
   currlen =0;
   }
   
   str++;
}
 
printf("maxlen = %d\n",maxlen);

return 0;
}
