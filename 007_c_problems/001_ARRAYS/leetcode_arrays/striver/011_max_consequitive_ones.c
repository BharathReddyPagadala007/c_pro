#include <stdio.h>

int findMaxConsecutiveOnes(int arr[], int n) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        } else {
            currentCount = 0; // Reset if a zero is encountered
        }
    }

    return maxCount;
}

int main() {
    int arr[] = {1, 1, 0,1,1,1,1, 1, 1, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findMaxConsecutiveOnes(arr, n);
    printf("Maximum consecutive ones: %d\n", result);

    return 0;
}

