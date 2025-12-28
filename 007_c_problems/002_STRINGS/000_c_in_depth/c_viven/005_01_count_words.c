#include<stdio.h>
//#include<string.h>
#include<ctype.h>


int main(){

	char str[] ="   Hello   world,\tthis is   C\nprogramming  ";
	char i=0;
	char word_count =0;
	char in_word=0;
	printf("---\n%s\n---\n",str);


	while(str[i]!='\0'){
	
	
		if(isspace((unsigned char)str[i])){

			in_word=0;

		}else if(!in_word){   // else if(in_word ==0)  // only ifts not inword u increase word_Count
		
			word_count++;
			in_word=1;
		
		}
	
	
	
	i++;

	}


	printf("word_count == %d\n",word_count);




return 0;
}
