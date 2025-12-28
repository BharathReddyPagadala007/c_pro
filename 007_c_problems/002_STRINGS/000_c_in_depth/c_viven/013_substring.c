//Write a program in C to extract a substring from a given string.
//
// placement   
// cement is a substring in the placement
#include<stdio.h>

void  extract_substring(const char* src, char* dest, int start, int length){

int i=0;

while(i<start && src[i]!='\0'){
	i++;
}

int j=0;
while(j<length && src[i]!='\0'){
	dest[j]=src[i];
	j++;
	i++;
}
dest[j]='\0';
//return dest;
}

int main(){

	char str[] ="EmbeddedSystems";
	char sub[20];


	int start =8;
	int length =7;

	extract_substring(str,sub,start,length);
	//from str u extract and put it in sub 
	//the starting index is 8 and 7 charachters are extraceted ie. copied
	//
	printf("original string: %s....s[8] %cto s[14]%c\n",str,str[8],str[14]);
	printf("extracted string: %s\n",sub);


return 0;
}
