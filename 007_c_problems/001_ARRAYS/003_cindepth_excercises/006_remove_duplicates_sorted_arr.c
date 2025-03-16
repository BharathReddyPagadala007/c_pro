#include<stdio.h>

int removeDuplicates(int arr[], int n){


	int i,j;

	j=0;  			//index for unique elemnents

	for(int i=1; i<n; i++){
	    if(arr[j]!=arr[i]){
	      j++;
	     arr[j]=arr[i]; 
	    }

	
	}

return j+1;

}

int main(){
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removeDuplicates(arr, n);

    for(int i=0; i<n; i++){
      printf("%d  ",arr[i]);
    
    }
    printf("\n");



return 0;
}
