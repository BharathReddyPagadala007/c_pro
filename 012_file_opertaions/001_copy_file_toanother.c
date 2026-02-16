#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

	FILE *src,*dest;
	int c;


	src=  fopen(argv[1],"r");

	dest= fopen(argv[2],"w");

	while((c=fgetc(src))!=EOF){
		fputc(c,dest);
	}

	fclose(src);
	fclose(dest);

return 0;
}
