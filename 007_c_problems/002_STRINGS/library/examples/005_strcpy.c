#include<stdio.h>
#include<string.h>



int main(){

	char str1[20],str2[20];

	strcpy(str1,"this is first");   // u can use scanf or gets or fgets to obtain a string
	
	strcpy(str2,str1);
	printf("second string is %s\n",str2);



return 0;
}
