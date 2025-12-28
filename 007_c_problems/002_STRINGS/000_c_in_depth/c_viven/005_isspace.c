#include<stdio.h>
#include<ctype.h>


int main(){

	char ch1 = ' ';
	char ch2 = 'a';
	char ch3 = '  ';// 2 spaces means 2 bytes bbut char is just 1 byte
	char ch4 = '\n';
	char ch5 = '\t';
	char ch6 = '\r';



	if(isspace((unsigned)ch1))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch1);


	if(isspace((unsigned)ch2))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch2);



	if(isspace((unsigned)ch3))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch3);




	if(isspace((unsigned)ch4))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch4);


	if(isspace((unsigned)ch5))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch5);


	if(isspace((unsigned)ch6))
		printf("whitespace\n");
	else
		printf("%c not a white space\n",ch6);

return 0;
}
