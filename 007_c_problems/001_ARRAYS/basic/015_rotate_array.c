#include<stdio.h>


int main()
{

 int arr[]= {1,2,3,4,5,6,7};
 int rot[7];
 int lrt[7];

 int i,k,size;

 size = 7;
 k=3;
 k = k%size;

 for(i=0;i<size;i++)
 {
	 printf("%d ",arr[i]);
 
 }
 printf("\n");

 for(i=0;i<size;i++)	
 {
  rot[(i+k)%size]= arr[i];
  
 }

 for(i=0;i<size;i++)	
 {
  lrt[(i+size-k)%size]= arr[i];
  
 }

 for(i=0;i<size;i++)
 {
   arr[i]= rot[i];
 }

 for(i=0;i<size;i++)
 {
	 printf("%d ",arr[i]);
 
 }
 printf("\n");
   
 for(i=0;i<size;i++)
 {
   printf("%d  ",lrt[i]);
 }

 printf("\n");



return 0;
}
