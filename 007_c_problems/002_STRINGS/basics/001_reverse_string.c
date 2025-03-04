#include<stdio.h>
#include<string.h>


int main()
{
   char str[]= "hello world";
   //size_t len = strlen(str);
 //  printf("string is %s, %zu\n",str,len);

   int  len = strlen(str);
   printf("string is %s, %d\n",str,len);

   int i,j;
   char temp;

   for(i=0,j=len-1;i<j;i++,j--)
   {
    temp = str[i]; 
    str[i]=str[j];
    str[j]= temp;
   }
   /*
    * int start=0,end=len -1;
    *
   while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    */
   
   printf("string is %s, %d\n",str,len);


return 0;
}

////////////////////////////
//
//strlen(): Counts the characters up to (but not including) the null terminator.
//sizeof(): Returns the total size of the array, including the null terminator.
//
//////////////////
//
/*
 *     char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    // Swap characters from start to end until pointers meet in the middle
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;

    }
    */
