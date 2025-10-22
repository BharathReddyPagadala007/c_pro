#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    // Method 1: Using fgets (Safe Way)
    printf("Enter a string using fgets: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    printf("Using fgets: %s\n", str);

    // Method 2: Using scanf
    printf("\nEnter a string using scanf (without spaces): ");
    scanf("%s", str);
    printf("Using scanf: %s\n", str);

    getchar(); // Consume newline left by scanf

   // Method 3: Using gets (Unsafe, Not Recommended)
    printf("\nEnter a string using gets (UNSAFE): ");
    gets(str);
    printf("Using gets: %s\n", str); // Avoid using gets()

    // Method 4: Printing Character by Character using for loop
    printf("\nString printed character by character: ");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    // Method 5: Using Pointers
    printf("\nString using pointer: ");
    char *ptr = str;
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    return 0;
}

