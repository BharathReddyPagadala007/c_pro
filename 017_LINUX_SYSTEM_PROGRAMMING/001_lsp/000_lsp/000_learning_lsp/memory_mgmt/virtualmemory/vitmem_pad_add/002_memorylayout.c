#include <stdio.h>
#include <stdlib.h>

int global_var = 5; // Data segment

int main() {
    int local_var; // Stack segment
    int *heap_var = malloc(sizeof(int)); // Heap segment

    printf("Address of global_var (Data Segment): %p\n", (void*)&global_var);
    printf("Address of local_var (Stack Segment): %p\n", (void*)&local_var);
    printf("Address of heap_var (Heap Segment): %p\n", (void*)heap_var);
    printf("Address of main function (Text Segment): %p\n", (void*)&main);
    
    free(heap_var);
    return 0;
}

