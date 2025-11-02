#include<stdio.h>
#include<string.h>

int main()
{
	const char * src="hello";
	char * dest ="worls";

       memcpy(dest,src,5);

return 0;
}

//////////////////////
//segmentation fault
//
//
///////////////////////
