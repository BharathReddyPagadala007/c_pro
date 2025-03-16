#include<stdio.h>


unsigned reverse(unsigned x);
int main(){

	unsigned num= 0xDEADBEEF;
	unsigned rev;
	unsigned left_mask_2b = 0xFF00FF00;
	//unsigned left_mask_1b  = 0xF0F0F0F0;
	//unsigned right_mask_1b = 0x0F0F0F0F;
	unsigned right_mask_2b = 0x00FF00FF;
	unsigned new_left_2b,new_right_2b, new;


printf("num =0x%x\n",num);	
//rev= reverse(num);
//printf("rev =0x%x\n",rev);	


new_left_2b = left_mask_2b &  num;
printf("new_left_2b =0x%x\n",new_left_2b);	
new_right_2b = right_mask_2b &  num;
printf("new_right_2b =0x%x\n",new_right_2b);	

new = (new_right_2b <<8) | (new_left_2b>>8);  // >>2 <<2 is a disaster

printf("new =0x%x\n",new);	



return 0;

}

unsigned reverse_bytes(unsigned x){

//////////////////////////////////////////////////////////
//
//   DEAD BEEF <=====> FEEB DAED
//
//   
//

	unsigned rev ;
	unsigned x_upper,x_lower;

	x_upper = x>>16;












}
unsigned reverse(unsigned x){
  
	////////////////////////////////////////////////////////////////
	//   note this is a bit by bit reversal not byte by byte
	//   an int or an unsigned int has 32 bits that is 8 * 4bits===> here u have
	//   8 bytes
	//
	//   ------------------------------------------
	//
	//   so u are not reversing these bytes deadbeef <===> feebdaed
	//
	//
	//

	unsigned rev=0 ;  //unintialise rev can be a disaster
  //printf("x_num_tobe_rev =0x%x\n",x);	
	
	for(int i=0; i<32; i++){
	  
	 if((x & (1<<i))){
	 rev = rev | (1<<(31-i));
	 
	 }
	}


printf("rev =0x%x\n",rev);	
      

	return rev;
}



