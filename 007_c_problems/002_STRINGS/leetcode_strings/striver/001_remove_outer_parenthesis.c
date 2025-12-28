
#include <stdio.h>
#include <string.h>

//==============================================================
char* removeOuterParentheses(char* s) {
    int level = 0;
    int n = strlen(s);
    char* result = (char*)malloc(n + 1); // Allocate max possible space
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (level > 0) {
                result[index++] = s[i];
            }
            level++;
        } else {
            level--;
            if (level > 0) {
                result[index++] = s[i];
            }
        }
    }
    result[index] = '\0';
    return result;
}

//==============================================================
int main() {
    char s[] = "(()())(())";
    char* result = removeOuterParentheses(s);
    printf("Output: %s\n", result);
    free(result); // Free allocated memory
    return 0;
}

//==============================================================


