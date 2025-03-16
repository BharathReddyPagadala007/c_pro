#include <stdio.h>

#define MAX 100  // Define max size for stack

void findLeaders(int arr[], int n) {
    int stack[MAX];  
    int top = -1;  

    int max_from_right = arr[n - 1];  
    stack[++top] = max_from_right;  // Push the last element (always a leader)

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            stack[++top] = max_from_right;  // Push leader onto stack
        }
    }

    // Print leaders in correct order
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);
    return 0;
}

