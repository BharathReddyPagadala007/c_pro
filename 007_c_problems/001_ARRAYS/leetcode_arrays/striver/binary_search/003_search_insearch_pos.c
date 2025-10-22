#include <stdio.h>

// Function to perform binary search
int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) 
            return mid;  // Found the target, return index
        else if (arr[mid] > x)
            high = mid - 1;  // Search in left half
        else
            low = mid + 1;  // Search in right half
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int index = binary_search(arr, n, x);
    if (index != -1)
        printf("Element %d found at index %d\n", x, index);
    else
        printf("Element %d not found in the array\n", x);

    return 0;
}

