#include<stdio.h>

int main()
{

// dereferecing pointer variables

	int a=87;
	float b =4.5;
	int *p1 =&a;
	float *p2=&b;

	printf("value of p1 = address of a = %p \n",p1);
	printf("value of p2 = address of a = %p \n",p2);
	printf("address of p1 = %p \n",&p1);
	printf("address of p2 = %p \n",&p2);

	printf("value of a = %d %d %d\n", a, *p1,*(&a));
	printf("value of a = %f %f %f\n", b, *p2,*(&b));


return 0;
}
