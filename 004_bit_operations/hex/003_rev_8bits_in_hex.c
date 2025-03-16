/////////////////////////////////////////////////////////////////////
//Write a function that reverses the bits of a given 8-bit hexadecimal number.
//
//
#include<stdio.h>

void display_bits(int x);
int reverse_bits(int x);

int main(){

	int num = 0x53;

	printf("num = %x\n",num);
	display_bits(num);
	int rev =reverse_bits(num);
	printf("rev = %x\n", rev);
	display_bits(rev);


return 0;
}

//////////////////////////////////////////////////////////////////////////////


int reverse_bits(int num){

int rev=0;
  
  for(int i=0; i<8; i++){
	  rev<<=1;
	  rev= rev | (num&1);
	  num>>=1;

  }


  return rev;

}



//////////////////////////////////////////////////////////////////////////////

void display_bits(int x){

	int i;
	int mask;


	for(i=31; i>=0; i--){
		mask= 1<<i;
	
	   putchar(x&(mask)?'1':'0');
	
	}
	printf("\n");



}
