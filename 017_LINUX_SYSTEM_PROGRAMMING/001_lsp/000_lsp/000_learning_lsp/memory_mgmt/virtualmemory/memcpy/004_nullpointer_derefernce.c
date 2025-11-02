#include<stdio.h>
#include<string.h>


int main()
{
	char* src= NULL;
	char dest[10];

	memcpy(dest,src,5);

return 0;
}

/*
 *tai_wsl@tailung:/mnt/g/embsys/profile/cpro/LSP/virtualmemory/memcpy$ gcc 004_nullpointer_derefernce.c 
tai_wsl@tailung:/mnt/g/embsys/profile/cpro/LSP/virtualmemory/memcpy$ ./a.out 
Segmentation fault (core dumped)
 *
 * */

