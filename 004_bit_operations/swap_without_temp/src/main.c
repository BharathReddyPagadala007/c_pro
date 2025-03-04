#include<stdio.h>



int main(){


  printf("hello worlsd \n");


  int a =10;
  int b= 20;
  printf("before swapping: \n a: %d\n b: %d\n",a,b);

  a^=b;
  b^=a;
  a^=b;


  printf("after swapping: \n a: %d\n b: %d\n",a,b);

 return 0;
}
