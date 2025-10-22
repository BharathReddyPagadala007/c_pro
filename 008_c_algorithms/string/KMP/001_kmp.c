#include<stdio.h>
#include<string.h>

void KMP(char* text , char* pattern){

	int N = strlen(text);
	int M = strlen(pattern);

	printf("N=%d M=%d\n",N,M);


	printf("%s,%s\n",text,pattern);

	//---------------------------
	




}

int main(){


    char text[] = "abxabcabcaby";
    char pattern[] = "abcaby";
    KMP(text, pattern);

return 0;
}
