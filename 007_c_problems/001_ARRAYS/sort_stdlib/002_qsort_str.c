#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for strings
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    const char *arr[] = {"apple", "orange", "banana", "grape"};
    size_t n = sizeof(arr) / sizeof(arr[0]);



    // Sorting the array
    qsort(arr, n, sizeof(const char *), compareStrings);


    printf("Sorted array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    return 0;
}

