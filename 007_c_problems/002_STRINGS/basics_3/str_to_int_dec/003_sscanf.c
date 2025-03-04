#include<stdio.h>
#include<string.h>


int main()
{
   char str[] = "1234";
   int num;

   sscanf(str,"%d",&num);
   printf("num == %d\n",num);

return 0;
}
