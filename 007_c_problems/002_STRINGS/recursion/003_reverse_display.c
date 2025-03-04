#include<stdio.h>
void rev_display(char * str);
int main()
{
   char * str = "hello world";

    rev_display(str);
return 0;
}

void rev_display(char * str)
{
   if(*str == '\0')
   {    printf("\n");
	   return ;
   }

   rev_display(str+1);
   putchar(*str);
}
