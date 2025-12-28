// Write a program in C to count the total number of alphabets, digits and special characters in 
//a string. 

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(){


	char str[50] = "123abcDEF&*";

	int len = strlen(str);
	printf("%dlen\n",len);


		int vowel,special,cons,digit;
		vowel =digit=cons=special=0;

	for(int i=0; i<len; i++){

		if(isalpha(str[i])){
		char ch =tolower((unsigned char)str[i]);
			if(ch == 'a' || ch =='e' || ch == 'i' || ch == 'o'  || ch == 'u'){
				vowel++;
			}else{
				cons++;
			}

		}else if(isdigit(str[i])){
			digit++;
		
		}else{
			special++;
		}
	
	}
	printf("speacial= %d,digit= %d, cons= %d, vowel= %d\n",special,digit,cons,vowel);


return 0;
}
