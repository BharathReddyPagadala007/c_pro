#include<stdio.h>
#include<stdlib.h>


int main(){

	FILE *src, *dest;

	int ch;


	src= fopen("source.txt","r");
	dest = fopen("dest.txt","w");


	while((ch =fgetc(src))!=EOF){
		fputc(ch,dest );
	
	}
fclose(src);
fclose(dest);
return 0;
}
