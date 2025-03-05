#include<stdio.h>
void print_bit_pattern(int a){

for(int i =31; i>=0; i--){

printf("%d",((a>>i)&1));

if(i%4==0){
printf("  ");}

}
printf("\n");

}

int main(){

	int a=5, b=7;

	int carry;

	while(b!=0){
	 carry = a&b;
	 a= a^b;
	 b = carry<<1;
	 printf("a= "); print_bit_pattern(a); printf("\n");
	 printf("b= "); print_bit_pattern(b); printf("\n");
	}

	printf("sum i s--> %d\n",a);





return 0;
}
