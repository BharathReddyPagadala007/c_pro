//Write a program in C to find the number of times a given word 'the' appears in the given 
//string.
#include <stdio.h>
#include <ctype.h>

int is_word_boundary(char c)
{
    return (c == ' ' || c == '\0' || c == '.' || c == ',' ||
            c == '!' || c == '?' || c == '\n');
}

int count_the(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        /* check for "the" */
        if ( (i == 0 || is_word_boundary(str[i - 1])) &&
             tolower(str[i])     == 't' &&
             tolower(str[i + 1]) == 'h' &&
             tolower(str[i + 2]) == 'e' &&
             is_word_boundary(str[i + 3]) ) {

            count++;
            i += 3;   // skip past "the"
        } else {
            i++;
        }
    }
    return count;
}

int main()
{
    char str[200];

    printf("Enter string:\n");
    fgets(str, sizeof(str), stdin);

    printf("Number of times 'the' appears: %d\n", count_the(str));

    return 0;
}

