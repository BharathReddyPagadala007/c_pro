#include<stdio.h>


int main(){

	const int a =10;
	int * p =&a;
	printf("a= %d\n",a);
	//a=20;
	*p= 20;
	printf("a= %d\n",a);

return 0;
}
