#include<stdio.h>
#include<string.h>


int main()
{
   char* strs[] = {"flower", "flow", "flight"};

   int n = strlen(strs[0]);
   
   int i;

   int strs_len  = sizeof(strs)/sizeof(strs[0]);
   printf("----------------------------\n");
   printf("sizeof strs is --> %ld\n",sizeof(strs));
   printf("sizeof strs is --> %ld\n",sizeof(strs[0]));
   printf("number of elements int strs is --> %d\n",strs_len);
   printf("----------------------------\n");
   for(i=0;i<strs_len;i++)
   {
   printf("string lists length ==%ld\n",strlen(strs[i]));
   }

   printf("----------------------------\n");
   for(i=0;i<strs_len;i++)
   {
      printf("sizeof -- strs[%d]--> %ld\n",i,sizeof(strs[i]));
   }
   printf("----------------------------\n");


   printf("============ADDRESS===============\n");
   printf("strs-address  %p\n",strs);
   for(i=0;i<strs_len;i++)
   {
   printf("strs[%d]--address  ==%p \n",i,strs[i]);
   }

   printf("----------------------------\n");

   
   printf("=====================================\n");
   printf("=====================================\n");
printf("Memory Layout:\n");
    printf("| %s | %s | %s | %s |\n", "strs[]", "strs[0]", "strs[1]", "strs[2]");
    printf("|-----------------------|-------------------|-------------------|-------------------|\n");

    // Print addresses of strs[], strs[0], strs[1], strs[2]
    printf("| %p | %p | %p | %p |\n", strs, strs[0], strs[1], strs[2]);

    // Print the actual strings in memory
    printf("Memory for each string:\n");
    for (int i = 0; i < strs_len; i++) {
        printf("%s -> %p: ", strs[i], strs[i]);
        
        // Print the characters of the string with addresses
        for (int j = 0; strs[i][j] != '\0'; j++) {
            printf("'%c'", strs[i][j]);
        }
        // Print the null terminator
        printf("'\\0'->%p\n", &strs[i][strlen(strs[i])]);
    }
   printf("=====================================\n");

return 0;
}
