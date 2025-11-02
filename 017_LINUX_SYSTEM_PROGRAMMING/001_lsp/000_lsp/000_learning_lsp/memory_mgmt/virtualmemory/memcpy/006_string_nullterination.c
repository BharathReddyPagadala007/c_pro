#include<stdio.h>
#include<string.h>

int main()
{
	char src[10]= "hello";
	char dest[10];
	dest[9]='t';

	memcpy(dest,src,strlen(src));
	printf("%c\n",dest[9]);
	printf("%s\n",dest);

return 0;
}
