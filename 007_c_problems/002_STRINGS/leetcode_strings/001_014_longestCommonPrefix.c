#include<stdio.h>
#include<string.h>

char* longestCommonPrefix(char** strs,int strsSize)
{
   char* prefix = strs[0];
   
   if(strsSize ==0) return "";

   int i;

   for(i=1; i<strsSize; i++){
   
   	   while(strncmp(prefix,strs[i],strlen(prefix))!=0){
	   prefix[strlen(prefix)-1]='\0';
	   if(strlen(prefix)==0) return "";
         }

   
   }


return prefix;
}



int main()
{
     char *strs[] = {"flower", "flow", "flight"};
      int  size   = sizeof(strs) / sizeof(strs[0]);

    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs, size));

return 0;
}
