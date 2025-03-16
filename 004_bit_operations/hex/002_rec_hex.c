#include<stdio.h>
#include<stdint.h>

uint32_t swap(uint32_t org_hex);
uint32_t swap2(uint32_t org_hex);


int main(){

	unsigned num= 0xDEADBEEF;
	unsigned rev;


printf("num =0x%x\n",num);	

rev = swap(num);


printf("swp =0x%x\n",rev);	
swap2(num);


return 0;

}

uint32_t swap(uint32_t org_hex){

//////////////////////////////////////////////////////////
//
//   DEAD BEEF <=====> FEEB DAED   reverse bytes
//
//   DEAD BEEF <=====> EFBE ADDE  SWAP BYTES
//
//   
//


	char* org_ptr = (char*)&org_hex;

	uint32_t len= sizeof(org_hex);
	//printf("len = %d\n",len);  4bytes

	for(uint32_t i=0; i<len/2; i++){
	
	  org_ptr[i]         = org_ptr[i] ^ org_ptr[(len-1)-i];
	  org_ptr[(len-1)-i] = org_ptr[i] ^ org_ptr[(len-1)-i];
	  org_ptr[i]         = org_ptr[i] ^ org_ptr[(len-1)-i];
	
	}


return org_hex;


}

////////////////////////////////////////////////////////////////////////////////////
//
//
//  swap using shifting

uint32_t swap2(uint32_t org_hex){

	uint32_t x_upper,x_lower,new_hex=0;
	x_upper=0;
	x_lower=0;

	x_upper = org_hex>>16;
	x_lower = org_hex & 0xFFFF;

	x_upper = x_upper >>8 | (x_upper & 0xFF)<<8;
	x_lower = x_lower >>8 | (x_lower & 0xFF)<<8;

	new_hex = x_lower <<16 | x_upper ;



	printf("sw2 ==0x%x\n",new_hex);
	return new_hex;

















}
///////////////////////////////////////////////////////////////////////////////////////
