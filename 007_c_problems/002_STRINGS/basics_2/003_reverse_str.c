//program that takjes  a string as a n argument and reverses it. write another
//write another function to reverse a portion only
//
#include<stdio.h>
#include<string.h>

///////////
void reverseStr(char str[]);
void reverse(char str[], int start , int end);
//////////////////

int main()
{
  char str[50];
  strcpy(str, "i have many books");

  reverseStr(str);
  puts(str);
  reverse(str,6,9);
  puts(str);
return 0;
}
/////////////////
void reverseStr(char str[])
{
  int i,j;
  char temp;

  for(i=0,j=strlen(str)-1;i<=j;i++,j--)
  {
     temp = str[j];
     str[j]= str[i];
     str[i]= temp;
  }
}


void reverse(char str[],int start, int end)
{
  int i,j;
  char temp;

  while(start<= end)
  {
     temp = str[end];
     str[end]= str[start];
     str[start]= temp;
     start++;
     end--;
  }
}

