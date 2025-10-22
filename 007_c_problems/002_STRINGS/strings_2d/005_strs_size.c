#include<stdio.h>
#include<string.h>
//longestCommonPrefix(char** strs, int strs_size);
int main(){
    
    char* strs[] = {"flower", "flow", "flight","flowered", "flowervase"};
    int size = sizeof(strs) / sizeof(strs[0]);
    printf("size-- %d\n",size);
    
    for(int i=0; i<size; i++){
        printf("easch string size--%ld\n",sizeof(strs[i]));
    }
    
  //  printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs, size));
    
    
    return 0;
    
}

    
