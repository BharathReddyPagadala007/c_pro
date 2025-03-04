#include<stdio.h>

int fib(int n){

	printf("===================================\n");
	printf("  fib(%d)-->\n",n);
	if(n==0)  {   printf("return 0\n"); return 0;}
	if(n==1)  {   printf("return 1\n"); return 1;}

	
	return fib(n-1)+fib(n-2);

}
///////////////////////////////////////////////////////////////

// Fibonacci function with winding and unwinding prints
int fibonacci(int n) {
    printf("Entering fibonacci(%d)\n", n); // Winding
    if (n <= 1) {
        printf("Base case reached: fibonacci(%d) = %d\n", n, n);
        return n; // Base case: return n when n is 0 or 1
    }
    
    int result = fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    printf("Returning from fibonacci(%d): Result = %d\n", n, result); // Unwinding
    return result;
}







///////////////////////////////////////////////////////////////

int main()
{

    int n;
    n=10;

    printf("fibonacci nth f(n)\n");
    printf("fib(%d)==>%d\n",n,fibonacci(n));

return 0;
}


