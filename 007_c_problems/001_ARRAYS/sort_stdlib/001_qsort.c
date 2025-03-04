#include <stdio.h>
#include <stdlib.h>

// Comparison function for integers
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Cast to int* and dereference
}

int main() {
    int arr[] = {40, 10, 100, 90, 20, 25};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array
    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

