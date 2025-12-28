#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[200];
    char *token;
    int count = 0;

    printf("Enter string:\n");
    fgets(str, sizeof(str), stdin);

    /* delimiters: space and punctuation */
    token = strtok(str, " ,.!?\n");

    while (token != NULL) {
        if (strcasecmp(token, "the") == 0) {
            count++;
        }
        token = strtok(NULL, " ,.!?\n");
    }

    printf("Number of times 'the' appears: %d\n", count);

    return 0;
}

