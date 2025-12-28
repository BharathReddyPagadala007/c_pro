// Write a program in C to remove characters from a string except alphabets.
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[200];
    int i = 0, j = 0;

    printf("Enter string:\n");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (isalpha((unsigned char)str[i])) {
            str[j++] = str[i];
        }
        i++;
    }

    str[j] = '\0';

    printf("String after removing non-alphabets:\n%s\n", str);

    return 0;
}

