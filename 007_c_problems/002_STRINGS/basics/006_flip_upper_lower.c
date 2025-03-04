/*
 Convert Lowercase to Uppercase and Vice Versa
Write a function to convert all lowercase letters to uppercase and vice versa.
Example:
Input: "Hello World"
Output: "hELLO wORLD"
*/
//////////////////////////////////////////////
#include<stdio.h>
#include<string.h>


int main()
{
  char str[] = "Hello World";
    
  int len = strlen(str);
  int i=0;
  for(i=0;i<len-1;i++)
  if(str[i] >= 'a'  && str[i] <= 'z')
  {
     str[i] = str[i] -32;
  }
  else if(str[i] >= 'A' && str[i] <= 'Z')
  {
   str[i] = str[i] + 32;
  }
  printf("string after modificvation : %s\n",str);


return 0;
}


