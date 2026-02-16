#include<stdio.h>


int main(void){

	

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
