///////////////////////////////////////////////////////////////
//    from an unsorted array
//
//    sort in ascending order and descending order
//
//   when u find a duplicate u break when u dont find continue
//
//
//
//

#include<stdio.h>

int remove_dup(int arr[], int n){

	if(n==0 || n==1){
	return n;
	}
	int i,j,k;
	int dup;
	k=0;

	for(i=0; i<n; i++){
		dup=0; 					 //reset dup=0;
		for(j=0; j<k; j++){
							// Check if arr[i] is already in the unique part (arr[0..j-1])
			if(arr[i]==arr[j]){
				dup =1;
				break;
			}
		}

		if(!dup){
		arr[k++]=arr[i];
		}
	}

return k;
}

int main(){

	int arr[] = {3, 5, 3, 2, 8, 5, 6, 8, 2, 9};
        int n = sizeof(arr) / sizeof(arr[0]);

	int new_size = remove_dup(arr,n);

	printf("new array after removing duplicates:\n");

	for(int i=0; i<new_size; i++){
	printf("%d  ",arr[i]);
	}
	printf("\n");




	

return 0;
}
