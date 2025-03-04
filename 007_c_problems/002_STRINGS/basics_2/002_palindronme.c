// program to test whether a string is a palindrome or not
#include<stdio.h>
#include<string.h>

int main()
{
  char str[50];
  int i,j;

  printf("entera string::: ");
  //gets(str); 
  fgets(str,sizeof(str),stdin);

  str[strcspn(str,"\n")]  ='\0';
  //fgets After reading the string with fgets, you should remove the trailing newline character (\n) if it exists. This  // can be done by replacing the newline character with '\0'
  //
  //
  
  puts(str);

  for(i=0,j=strlen(str)-1;  i<=j; i++,j--)
  {
     if(str[i]!=str[j])
     {
       break;
     }
  }

  if(i>j)
  {
    printf("palindrome\n");
  }
  else
  {
    printf("not a palindrome\n");
  }

return 0;
}

