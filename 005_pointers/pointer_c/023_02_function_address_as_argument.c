#include<stdio.h>


void func(char, void (*fp)(float));
void func1(float);

int main()
{
  printf("function main() called %p\n",main);
  func('a',func1);


return 0;
}


void func(char b, void (*fp)(float) )
{
 printf("func called %p\n",func);
 (*fp)(6.5);
}

void func1(float f )
{
 printf("func1 called %p\n",func1);
}



