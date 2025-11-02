#include<stdio.h>
#include<string.h>


int main()
{

	char src[20]= "helloworld";
	char dest[20];


	memcpy(dest,src,strlen(src)+1);


	printf("src: %s\n",src);
	printf("dest: %s\n",dest);




return 0;
}
