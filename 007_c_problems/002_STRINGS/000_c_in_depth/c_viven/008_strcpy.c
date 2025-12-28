//Write a program in C to copy one string to another string. 
#include<stdio.h>
#include<string.h>
#include<ctype.h>



int main(){


	char str1[] = "bharath";
	char str2[20];

	mystrcpy(str2,str1);

	printf("str2=%s\n",str2);




return 0;
}
