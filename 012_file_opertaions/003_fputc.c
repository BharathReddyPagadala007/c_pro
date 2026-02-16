#include<stdio.h>
#include<stdlib.h>
int main(){


	FILE * fp;

	int ch;


	fp = fopen("myfile.txt","w");

	printf("enter text\n---->to end ctrl + D\n");

	while((ch=getchar())!=EOF){
		fputc(ch,fp);
	
	}

	fclose(fp);


return 0;
}
