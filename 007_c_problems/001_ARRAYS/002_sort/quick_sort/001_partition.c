#include<stdio.h>


 int    partition(int arr[],int low,int high);
 void swap(int* pa, int* pb);

int main(){
    int arr[] = {3,10,11,12,2,3,3,0,4, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");

    for(int i=0; i<n; i++){
    
      printf("%d  ",arr[i]);
    }
    printf("\n");

    partition(arr,0,n-1);
    //partition(arr,low,high);



return 0;
}



int  partition(int arr[],int low,int high){



    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++){
//	    printf("i=%d j=%d--->%d\n",i,j,arr[j]);
       
	    if(arr[j]<=pivot){

	      i++;
	    
	    // printf(" i = %d, j==%d   arr[j<=pivot]--->>%d  ",i,j,arr[j]);

	      printf("swapp i=%d arr[i]=%d j=%d arr[j]=%d  <<piv %d",i,arr[i],j,arr[j],pivot);
	      swap(&arr[i],&arr[j]);

	      printf("\n");
	        for(int k=0;k<high; k++){

    			printf("%d ",arr[k]);
    		}
	    printf("\n");
	    printf("-----------------------------\n");
	    
	    }
    
    }
    printf("\n");
    swap(&arr[i+1],&arr[high]);
    printf("\n");


    for(int k=0;k<high; k++){
    
    printf("%d ",arr[k]);
    }
    printf("\n");

return (i+1);

}




 void swap(int* pa, int* pb){
  int temp = *pa;
       *pa = *pb;
       *pb = temp;
 
 
 
 }
