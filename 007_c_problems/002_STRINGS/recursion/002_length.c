#include<stdio.h>
int  length(char * str);
int main()
{
   char * str = "hello world";

   int len;

   len =  length(str);
   printf("length  == %d\n",len);
return 0;
}

int  length(char * str)
{
   if(*str == '\0')
   {  
	   return 0;
   }
   
   
   return (1 + length(str +1));

}
