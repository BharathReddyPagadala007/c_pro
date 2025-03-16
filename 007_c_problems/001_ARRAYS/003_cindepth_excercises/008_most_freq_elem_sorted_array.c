/////////////////////////////////////////////////////////
//
//
//  most freqent element in sorted array
//
//

#include<stdio.h>

int most_freq_linear(int arr[],int n);
int most_freq_binary(int arr[],int n);


int main(){


	    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5};
   	    int n = sizeof(arr) / sizeof(arr[0]);



	    int most_freq = most_freq_linear(arr,n);
	    printf("most_freq_elem--= %d\n",most_freq);

//	    most_freq_binary(arr,n);


return 0;
}


int most_freq_linear(int arr[],int n){


	int count=1;
	int max_count=0;
	int most_freq;


	for(int i=1; i<n; i++){
	
		if(arr[i]==arr[i-1]){
		
			count++;
		
		}else{
		
		  if(count> max_count){
			  
			  most_freq= arr[i-1];
			  max_count = count;
		
		}
		  count=1;

		}

	}



	if(count>max_count){     //check the last element
	
	  most_freq = arr[n-1];
	}


	printf("\n");


	return most_freq;

}
//////////////////////////////////////////////////////////////////
//
//
//
//  binary search
//
//
int most_freq_binary(int arr[],int n){






}


