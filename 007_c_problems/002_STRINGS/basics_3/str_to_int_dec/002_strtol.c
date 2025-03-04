#include<stdio.h>
#include<stdlib.h>

int main()
{
  char str[]= "1234";
  int num ;

  char * end;

  num = (int ) strtol (str,&end,10);
  printf("%d---\n",num);
return 0;
}
