/*
Count the Number of Vowels and Consonants
Write a function to count the number of vowels and consonants in a given string.
Example:
Input: "hello world"
Output: Vowels: 3, Consonants: 7
*/


#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>


int main()
{
  
  char * str = "hello world";

  int len = strlen(str);
  int vowel=0, conson =0;

  while(*str)
  {
      char ch = tolower(*str);

      if(ch == 'a' || ch == 'e'|| ch == 'i' || ch == 'o' || ch == 'u' )
      {
        vowel++;
      }
      else if (ch >= 'a' &&  ch <='z')
      {
        conson++;

      }

      str++;
  
 }

      printf("v= %d , c= %d\n",vowel,conson);

return 0;
}
