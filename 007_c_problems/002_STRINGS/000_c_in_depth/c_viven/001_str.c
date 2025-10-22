//Write a program in C to input a string and print it

#include<stdio.h>
#include<string.h>


int main(){

	char str[20];
	char str2[20];
	char str3[20];

	//printf("enter a string:\n");
	//scanf("%s",str);
	//printf("string is :\n%s\n",str);

	//printf("2. enter a string:\n");
	//gets(str2);
	//printf("2.string is :\n%s\n",str2);


	printf("3. enter a string ():\n");
	fgets(str3,sizeof(str3),stdin);
	str3[strcspn(str3,"\n")]= '\0';
	printf("3.string read from stdin using fgets is :\n%s\n",str3);



return 0;
}
