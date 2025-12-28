//Write a C program to sort a string array in ascending order.
//what is string array
//  
#include<stdio.h>
#include<string.h>


int main(){
	char arr[][100] ={ 	 "apple",
				 "mango",
				 "grapes",
				 "dates",
				 "banan",
				 "cat",
	};

	int n= sizeof(arr)/sizeof(arr[0]);
	char temp[100];
	int i,j;

	for( i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){

			if(strcmp(arr[i],arr[j])>0){
			
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}

	printf("sorted strings in asc order\n");
	for(int i=0; i<n; i++){
		printf("%s\n",arr[i]);
	}



return 0;
}
//===============================================
