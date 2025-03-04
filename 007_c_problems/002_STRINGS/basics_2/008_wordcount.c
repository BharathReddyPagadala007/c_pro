#include<stdio.h>
#include<ctype.h>


int count_words(char * str);
int main()
{
  char str[50]  = "blue green red";
  printf("num of words in string =  %d\n", count_words(str));

return 0;
}

int count_words(char * str)
{
   int count = 0;

   while(*str!= '\0')
   {
     // while it is space until its end str++
     // if there is a non space char it is time to str++ 
     while(isspace(*str))
     {  str++;
     }

     if(*str == '\0')
    {	 return count;}

     while( !isspace(*str) && *str != '\0')
     {
       putchar(*str);
       str++;	   
     }
     count++;
     printf("\n");

   }

return count;
}
