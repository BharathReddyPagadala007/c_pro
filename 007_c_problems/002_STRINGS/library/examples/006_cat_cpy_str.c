#include<stdio.h>
#include<string.h>



int main(){

char str1[20]= "subhash ";
char str2[20]= "chandra ";
char str3[30];

strcat(str1,str2);
strcat(str1, "bose");


printf("name :%s\n",str1);

strcat(strcpy(str3,"bharath  "),"reddy");
printf("name :%s\n",str3);

return 0;
}
