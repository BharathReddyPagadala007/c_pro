/////////////////////////////////////////////////////////
//
//
//  most freqent element in sorted array
//
//

#include<stdio.h>

int most_freq_binary(int arr[],int n);
int first_occ(int arr[],int n, int x);
int last_occ(int arr[],int n,  int x);


int main(){


	    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5};
   	    int n = sizeof(arr) / sizeof(arr[0]);



	    int most_freq = most_freq_binary(arr,n);
	    printf("most_freq_elem--= %d\n",most_freq);



return 0;
}


//////////////////////////////////////////////////////////////////
//
//
//
//  binary search
//  advantage: o(log n)
//  worst: o(n log n)
//  
//  better than linear search approach
//
//

int most_freq_binary(int arr[],int n){


	int max_count,most_freq;
	max_count=0;
	most_freq=arr[0];

	for(int i=0; i<n; ){

	   int first = first_occ(arr,n,arr[i]);
	   int last   = last_occ(arr,n,arr[i]);
	   int freq = last-first +1;

	   if(freq>max_count){
	   most_freq = arr[i];
	   max_count= freq;

	   
	   }
	   i=last+1;
	
	
	}

  printf("Most frequent element: %d\n", most_freq);


return most_freq;


}


////////////////////////////////////////////////////////////////////
//
//
//first occurence of an element x
//
//
//
//   in binary search while(low<=hgh )  because we need to  get the single element
//
//
//
//
//   If low == high, it means there is only one element left to check, so we must process it. Otherwise, we may miss valid occurrences.

int first_occ(int arr[],int n,int x){

	int low, high, mid,result;
	low=0,high=n-1,result=-1;

	while(low <= high){
	
	  mid = low + (high-low)/2;

	  if(arr[mid]==x){
		  result =mid;
		  high = mid -1;
	  
	  }else if(arr[mid]< x){

		  low = mid+1;

	  
	  }else{
		  high = mid-1;
	  
	  
	  }
	
	}

return result;

}
int last_occ(int arr[],int n, int x){

	int low, high, mid,result;
	low=0,high=n-1,result=-1;



        while(low <= high){

          mid = low + (high-low)/2;

          if(arr[mid]==x){
                  result =mid;
                  low = mid +1;

          }else if(arr[mid]< x){

                  low = mid+1;


          }else{
                  high = mid-1;


          }

        }

return result;


}



