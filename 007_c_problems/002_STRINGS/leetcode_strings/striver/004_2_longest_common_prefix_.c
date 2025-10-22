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
					//


        char* prefix= strs[0];

    int i;

    for(i=1; i<strs_size; i++){
        while(strncmp(prefix,strs[i],strlen(prefix))!=0){

            if(strlen(prefix)==0) return "";
		prefix[strlen(prefix)-1]='\0';
        }
    }

return prefix;

}

