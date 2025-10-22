
///////////////////////////////////////////////////////////////////////////
/*
Replace Each Element with the Greatest Element to its Right

Problem: Update each element in an array to the greatest element among the elements to its right.
Example: For [16, 17, 4, 3, 5, 2], the result is [17, 5, 5, 5, 2, -1].
Hints: Traverse the array from the right while keeping track of the maximum value.

*/
///////////////////////////////////////////////////////////////////////////
//
#include<stdio.h>

void print_array(int arr[], int n){

	for(int i=0; i<n; i++){
	
	printf("%d ",arr[i]);
	}
	printf("\n");

}
int main(){
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);


    print_array(arr,n);

    int max_right =-1;


    for(int i=n-1; i>=0; i--){
       int temp = arr[i];
       
       arr[i]= max_right;


       if(temp> max_right){
	       max_right = temp;
    
       }
    }

       print_array(arr,n);


return 0;
}
