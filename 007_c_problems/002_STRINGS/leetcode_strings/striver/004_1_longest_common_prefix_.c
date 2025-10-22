#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function declaration
char* longestCommonPrefix(char** strs, int strs_size);

int main() {
    char* strs[] = {"flower", "flow", "flight", "flowered", "flowervase"};
    int size = sizeof(strs) / sizeof(strs[0]);
    printf("Size: %d\n", size);

    for (int i = 0; i < size; i++) {
        printf("String: %s, Length: %ld\n", strs[i], strlen(strs[i]));
    }

    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs, size));

    return 0;
}

char* longestCommonPrefix(char** strs, int strs_size) {
    if (strs_size == 0) return ""; // Handle empty array
    if (strs_size == 1) return strs[0]; // Single string case

    for (int i = 0; strs[0][i]; i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs_size; j++) {
            if (strs[j][i] != c || strs[j][i] == '\0') {
                // Allocate memory for the result
                char* result = (char*)malloc((i + 1) * sizeof(char));
                strncpy(result, strs[0], i);
                result[i] = '\0';
                return result;
            }
        }
    }
    return strdup(strs[0]); // If no mismatch is found
}

