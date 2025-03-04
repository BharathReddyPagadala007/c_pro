/*
 *
 *
//////////////////////////////////////////////
 *
 *	 float (*fp) (int,float);
 	 (float *)  fp (int,float);
	   are these both samei???
//////////////////////////////////////////////
//float (*fp)(int, float); is a declaration of a function pointer.
//(float *) fp(int, float); is an expression that involves calling a function through a pointer and casting the result.
//////////////////////////////////////////////
*/
//
//////////////////////////////////////////////
#include<stdio.h>

float add(int ,float);
float result;

int main()
{

  float (*fp) (int,float); 
  float result;

  fp= add;

  result = add(5,6.6);
  printf("%f\n",result);

return 0;
}
float add(int a , float b)
{
return  a+b;
}
