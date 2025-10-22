#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int xorTotal = 0;
    int xorArray = 0;

    // XOR all numbers from 1 to N
    for (int i = 1; i <= n; i++) {
        xorTotal ^= i;
    }

    // XOR all array elements
    for (int i = 0; i < n - 1; i++) {
        xorArray ^= arr[i];
    }

    // Missing number
    return xorTotal ^ xorArray;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6; // Total numbers from 1 to N

    int missing = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missing);

    return 0;
}

