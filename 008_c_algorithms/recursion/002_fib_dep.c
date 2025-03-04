#include <stdio.h>

int depth = 0; // Global variable to track the depth of recursion

// Fibonacci function with indentation for better interpretation
int fibonacci(int n) {
    // Print spaces based on recursion depth for better visualization
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Entering fibonacci(%d)\n", n); // Winding

    depth++; // Increase depth for the next recursive call

    if (n <= 1) {
        // Base case
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("Base case reached: fibonacci(%d) = %d\n", n, n);
        depth--; // Decrease depth before returning
        return n;
    }

    // Recursive case
    int result = fibonacci(n - 1) + fibonacci(n - 2);

    depth--; // Decrease depth after returning from recursion

    // Print spaces based on recursion depth for unwinding
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Returning from fibonacci(%d): Result = %d\n", n, result); // Unwinding

    return result;
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\nFibonacci series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

