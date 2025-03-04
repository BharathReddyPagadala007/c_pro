#include<stdio.h>
void display(char * str);
int main()
{
   char * str = "hello world";

    display(str);
return 0;
}

void display(char * str)
{
   if(*str == '\0')
   {    printf("\n");
	   return ;
   }

   putchar(*str);
   display(str+1);
}
