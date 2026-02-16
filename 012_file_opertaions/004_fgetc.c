#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE* fp;

	int ch;

	fp = fopen("myfile.txt","r");

	while((ch= fgetc(fp))!=EOF){
	
		printf("%c",ch);
	
	}
	fclose(fp);

return 0;
}
