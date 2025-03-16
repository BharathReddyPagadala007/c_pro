#include<stdio.h>

//  AND ( & )
// OR ( | )
// NOT ( ~ )
// XOR ( ^ )
// left shift ( << ) :multiply by 2
// right shift ( >> ) :divide by 2

int main()
{

printf("BEGIN:%s\n\n",__func__);

	int i=1; // 0.0.0.0001
	int j;
	unsigned char k;

/////////////////////////////////// left shift : multiple of 2 //////////////////////////////
	j=i<<1;
	printf("i=1 left shift by 1 (i.e.. 1<<1) makes it: %d \n ",j);
	
	j=i<<2;
	printf("i=1 left shift by 2 (i.e.. 1<<2) makes it: %d \n ",j);
	
	j=i<<3;
	printf("i=1 left shift by 3 (i.e.. 1<<3) makes it: %d \n ",j);
	
	j=i<<4;
	printf("i=1 left shift by 4 (i.e.. 1<<4) makes it: %d \n \n ",j);
///////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////// right shift : divided by 2 //////////////////////////////
	
	i=6;

	j=i>>1;
	printf("i=6 right shift by 1 (i.e.. 1>>1) makes it: %d \n ",j);
	
	j=i>>2;
	printf("i=6 right shift by 2 (i.e.. 1>>2) makes it: %d \n ",j);
	
	j=i>>3;
	printf("i=6 right shift by 3 (i.e.. 1>>3) makes it: %d \n ",j);

	j=i>>4;
	printf("i=6 right shift by 4 (i.e.. 1>>4) makes it: %d \n\n ",j);

///////////////////////////////////////////////////////////////////////////////////////////////


// AND
	i=1;
	
	j=i&1;
	printf("BITWISE AND(&):  1 & 1 = %d\n ",j);

	j=i&2;
	printf("BITWISE AND(&):  1 & 2 = %d\n ",j);

	j=i&3;
	printf("BITWISE AND(&):  1 & 3 = %d\n ",j);

	i=5;

	j=i&3;
	printf("BITWISE AND(&):  5 & 3 = %d\n ",j);
	
	j=i&4;
	printf("BITWISE AND(&):  5 & 4 = %d\n\n ",j);

///////////////////////////////////////////////////////////////////////////////////////////////


// NOT 
	
	k=255;
	k=~k;
	printf("BITWISE NOT(~):  ~255 = %d\n ",k);

	k=0;
	k=~k;
	printf("BITWISE NOT(~):  ~0 = %d\n ",k);

	k=128;
	k=~k;
	printf("BITWISE NOT(~):  ~128 = %d\n\n ",k);

// XOR
	
	k=0;
	k=k^255;
	printf("BITWISE XOR(^):  0^255 = %d\n ",k);

	k=9;
	k=k^5;
	printf("BITWISE XOR(^):  9^5 = %d\n ",k);

	
printf("END:%s\n",__func__);

return 0;

}



