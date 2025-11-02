#include<stdio.h>
#include<stdlib.h>

int global_var =5;

int main()
{

printf("%d-->%p\n",global_var,&global_var);
printf("main add: %p\n",&main);

return 0;
}
