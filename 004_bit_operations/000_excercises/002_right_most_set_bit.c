#include<stdio.h>
#include<stdint.h>


void display_bits(int x);

int main(){
	uint32_t   num1 =140;
	unsigned   num2 =140;
	int n= 140;

printf("num1= %d\n",num1);
	display_bits(num1);
printf("num1-1= %d\n",num1-1);
	display_bits(num1-1);
printf("~(num1-1)= %d\n",~(num1-1));
	display_bits(~(num1-1));

printf("(num1&(num1-1))= %d\n",(num1 & (num1-1)));
	display_bits((num1)&(num1-1)); // clear the right most set bit

printf("(num1&~(num1-1))= %d\n",(num1 & ~(num1-1)));
	display_bits((num1)&~(num1-1));  // position of right  most set bit
					 
	// to find whether a number is exact pow of 2 or not

	if(n && !(n & (n-1))){
	 printf("num is a pow of 2\n");
	}else{
	 printf("not a pow of 2\n");
	}



return 0;
}



//////////////////////////////////////////////////////////////////////////
//
//
//  display bits
//
void display_bits(int x){

int i,mask;

for(i=31; i>=0; i--){
 	mask = 1<<i;
	//if((x & mask)==1) ? putchar('1'): putchar('0');
	putchar((x& mask)?'1':'0' );
	
	if(i%4 ==0){
	  putchar(' ');
	}

}

printf("\n");


}
