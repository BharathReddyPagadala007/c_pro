#include<stdio.h>
int add(int a, int b)
{
return a + b;
}
int multiply(int a , int b)
{
return a * b;
}
int main()
{

  int (* operation)(int , int);

  operation = add;
  printf("addition::  %d\n",operation(5,3));
  /////

  operation = multiply;
  printf("multiply::  %d\n",operation(5,3));

return 0;
}
