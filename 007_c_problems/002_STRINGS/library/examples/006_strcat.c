#include<stdio.h>
#include<string.h>



int main(){

char str1[20],str2[20];

printf("enter two strings :\n");
gets(str1);
gets(str2);


printf("1 str: %s \t 2 str: %s\n",str1,str2);
strcat(str1,str2);
printf("1 str: %s \t 2 str: %s\n",str1,str2);

return 0;
}
