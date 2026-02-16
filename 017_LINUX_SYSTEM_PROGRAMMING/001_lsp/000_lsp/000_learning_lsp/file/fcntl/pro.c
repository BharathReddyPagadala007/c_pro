// prg 
//
//
//  to share nibbles in a number 
//  inuo  oxab
//  out  0xba
//
#include<stdio.h>
#include<stdint.h>



int main(){


uint8_t a= 0xba;




printf("%x\n",a);



a = (a)>>4 | (a)<<4;
printf("%x\n",a);
}
