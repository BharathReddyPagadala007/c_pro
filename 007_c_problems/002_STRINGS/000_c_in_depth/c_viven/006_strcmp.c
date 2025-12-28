//Write a program in C to compare two strings without using string library functions.
//
//=============================================================
#include<stdio.h>
#include<string.h>

//=============================================================
int my_strcmp(const char * str1, const char* str2){

	while(*str1 != '\0' && *str2!='\0'){
		if(*str1!=*str2){
		return (unsigned char)*str1-(unsigned char)*str2;
		}
	
	str1++;
	str2++;
	}

	if(*str1 == '\0' && *str2 == '\0' )  return 0;

return (unsigned char)*str1-(unsigned)*str2;
}

//=============================================================
int main(){

	char str1[] = "embedded  ";
	char str2[] = "embedded";

	int res = my_strcmp(str1,str2);
	printf("%d result\n",res);

return 0;
}

//=============================================================
