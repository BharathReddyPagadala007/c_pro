#include<stdio.h>
#include<string.h>
char* longestCommonPrefix(char** strs, int strs_size);

int main(){

    char* strs[] = {"flower", "flow", "flight","flowered", "flowervase"};
    int size = sizeof(strs) / sizeof(strs[0]);

    printf("size-- %d\n",size);

    for(int i=0; i<size; i++){
        printf("each string size--%ld\n",sizeof(strs[i]));
    }

    int strs0_size = strlen(strs[0]);

    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs, strs0_size));


    return 0;

}

char* longestCommonPrefix(char** strs, int strs_size){



	for(int i=0; strs[0][i]; i++){
		char c= strs[0][i];
	  for(int j=1; j<strs_size; j++){

		  if(strs[j][i]!=c || strs[j][i]== '\0')
		  {
		    strs[0][i]='\0';
		    return strs[0];
		  }
	  
	  }
	
	}


return  strs[0];
}
