#include <stdio.h>

int findSingleNumber(int arr[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        result ^= arr[i];  // XOR all elements
    }

    return result;
}

int main() {
    int arr[] = {4,4,6,1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int singleNumber = findSingleNumber(arr, n);
    printf("The single number is: %d\n", singleNumber);

    return 0;
}

