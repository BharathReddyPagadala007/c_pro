/*
https://leetcode.com/problems/3sum/description/
*/

#include <stdio.h>

void threeSum(int arr[], int n) {
    int found = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("Triplet: (%d, %d, %d)\n", arr[i], arr[j], arr[k]);
                    found = 1;
                }
            }
        }
    }
    if (!found)
        printf("No triplets found\n");
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeSum(arr, n);
    return 0;
}

