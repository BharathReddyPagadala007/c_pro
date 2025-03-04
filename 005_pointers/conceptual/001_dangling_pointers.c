#include <stdio.h>
#include <stdlib.h>

void createDanglingPointer() {
    int *ptr = (int *)malloc(sizeof(int)); // Dynamically allocate memory
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    *ptr = 10;  // Assign a value to the allocated memory
    printf("Value before free: %d\n", *ptr);

    free(ptr);  // Deallocate the memory

    // Now ptr is a dangling pointer
    // Dereferencing it causes undefined behavior
    printf("Value after free: %d\n", *ptr);  // Dangerous: Accessing freed memory
}

int main() {
    createDanglingPointer();
    return 0;
}

