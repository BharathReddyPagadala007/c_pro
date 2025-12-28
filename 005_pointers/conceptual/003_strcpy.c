#include<stdio.h>
#include<string.h>


int main(){


	char* p = "abc";

	printf("%s\n",p);

	strcpy(p,"def"); //segmentation fault

	//strcpy(*p,"def");

	//printf("%s\n",p);
return 0;
}
