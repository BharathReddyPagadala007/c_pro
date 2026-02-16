#include<stdio.h>
#include<stdlib.h>
//==================================================
int isend(int ch){

	switch(ch){


		case '\n':
		case ' ':
		case '\t':
		case ',':
		case '.':
		case ':':
		case ';':
		case '-':
			return 1;
	
	
	}

	return 0;

}

//==================================================
int main(){

	char line[81];
	int count=0;


	FILE *fp;

	fp = fopen("source.txt","r");

	while(fgets(line,81,fp)){
	
		for(int i=0; line[i]!='\0'; i++){
			if(isend(line[i])){
			  count++;
			}
		}
	}


	printf("number of worsd in the fle =%d\n",count);
	fclose(fp);


return 0;
}
