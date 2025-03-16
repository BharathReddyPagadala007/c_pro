#include<stdio.h>

void count_setbits1(int x);
void count_setbits2(int x);
void count_setbits3(int x);
int main()
{
	int num;

	num = 140;

	count_setbits1(num);
	count_setbits2(num);
	count_setbits3(num);


return 0;
}


void count_setbits1(int x){
   int count =0, mask,i;

   for(i=0; i<32; i++){
    mask = 1<<i;

    if((x & mask )!=0){
	    count++;
    }
   }

   printf("count1 = %d\n",count);

return;

}
void count_setbits2(int x){

   int count =0;

   while(x!=0){
     if((x&1)!=0){
     
      count++;
     }
      x>>=1;
   }


   printf("count2 = %d\n",count);
return ;
}
void count_setbits3(int x){

   int count =0;

   while(x!=0){
    count++;
    x= x&(x-1);
   }

   printf("count3 = %d\n",count);

return ;
}
