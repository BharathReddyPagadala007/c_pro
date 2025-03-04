#include <string.h>
#include <stdio.h>

int main() {
    char str[] = "hello world ";
    char* str2 = "222 hello world";
    // Correctly initializing str3s as an array of string literals
    char* str3s[] = {"33hello", "33 world"};

    // Printing the individual strings
    printf("%s\n", str);    // Prints the first string
    printf("%s\n", str2);   // Prints the second string

    // Printing the strings from str3s
    // This prints each string in the array
    for (int i = 0; i < 2; i++) {
        printf("%s\n", str3s[i]);
    }

    return 0;
}

