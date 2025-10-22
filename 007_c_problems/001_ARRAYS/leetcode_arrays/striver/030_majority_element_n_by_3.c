/*
https://leetcode.com/problems/majority-element-ii/description/
 */

#include <stdio.h>
#include <stdlib.h>

void findMajorityElements(int arr[], int n) {
    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;

    // Step 1: Find potential candidates
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate1)
            count1++;
        else if (arr[i] == candidate2)
            count2++;
        else if (count1 == 0) {
            candidate1 = arr[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = arr[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify candidates
    count1 = count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate1) count1++;
        else if (arr[i] == candidate2) count2++;
    }

    // Step 3: Print results
    int threshold = n / 3;
    if (count1 > threshold) printf("%d ", candidate1);
    if (count2 > threshold) printf("%d ", candidate2);
    if (count1 <= threshold && count2 <= threshold) printf("No majority elements");
    printf("\n");
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMajorityElements(arr, n);
    return 0;
}

