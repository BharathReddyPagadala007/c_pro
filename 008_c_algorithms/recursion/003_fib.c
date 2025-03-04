#include <stdio.h>

int depth = 0; // Global variable to track the depth of recursion

// Fibonacci function with arrows for better interpretation
int fibonacci(int n) {
    // Print spaces based on recursion depth for better visualization
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("→ Entering fibonacci(%d)\n", n); // Winding with arrow

    depth++; // Increase depth for the next recursive call

    if (n <= 1) {
        // Base case
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("← Base case reached: fibonacci(%d) = %d\n", n, n); // Unwinding base case with arrow
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
    printf("← Returning from fibonacci(%d): Result = %d\n", n, result); // Unwinding with arrow

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

