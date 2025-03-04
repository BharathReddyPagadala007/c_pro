/*
 Remove All Duplicate Characters
Write a function to remove all duplicate characters in a string.
Example:
Input: "programming"
Output: "progamin"
*/


#include<stdio.h>
#include<string.h>

int main()
{
  //char * str = "programming";  //this is read only since its a string literal instead a array is recommended
  char str[] ="programming";
  int len = strlen(str);
  printf("%c\n",*(str+4));

  int i,index=0;
  int seen[256]={0};

  for(i=0;i<len -1; i++)
  {
       if(!seen[(unsigned char)str[i]])
       {
          str[index++]= str[i];
	  seen[(unsigned char)str[i]]=1;
       
       }
  }
  str[index]= '\0';

  printf("afytter removing duplicates::: %s\n",str);
return 0;
}
