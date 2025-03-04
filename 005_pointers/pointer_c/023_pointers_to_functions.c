#include<stdio.h>
void func1();
int func2(int),i;

float add(int , float);
int main()
{
	printf("address of function main= %p\n",main);
	printf("address of function func1= %p\n",func1);
	printf("address of function func2= %p\n",func2);
	i=10;
	printf("i =%d\n",i);
	func2(13);







return 0;
}
void func1(void)
{

printf("func1 inside \n");
}
int  func2(int x)
{
i=x;
i++;

printf("func2 inside=%d \n",i);
return x;

}
