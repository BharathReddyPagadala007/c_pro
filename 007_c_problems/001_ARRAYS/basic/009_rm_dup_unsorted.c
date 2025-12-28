/////////////////////////////////////////////////
//remove duplicates
/*
 * Remove Duplicates

Problem: Modify an array to remove all duplicate elements.
Example: [1, 3, 3, 5, 5, 7] becomes [1, 3, 5, 7].
Hints: Use a temporary array or mark elements as "seen" to filter out duplicates.
*/
////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>


int  compare(const void *a , const void *b){

return (*(int *)a - *(int *)b);
}
int main()
{

  int arr[]= {1,3,7,8,10,13,17,27,37,3,5,5,7,8,9,9,10,11,11,13};

  int n = sizeof(arr)/sizeof(arr[0]);
  int unique =1;
  int i;

for(i=0;i<n;i++)                                                                                                                                                
  printf("%d\t",arr[i]);     
printf("--------------\n");


  ////////////////////////////////////////////////
  //
  //  UN SORTED ARRAY
  /////////////////////////////////////////////////

  qsort(arr,n,sizeof(int),compare);

for(i=0;i<n;i++)                                                                                                                                                
  printf("%d\t",arr[i]);     
printf("--------------\n");

  for(int i=1; i<n; i++){
	  if(arr[i-1]!= arr[unique]){
		  arr[unique]= arr[i];
		  unique++;
	  
	  }
  
  }


/////////////////////////////////////////////////////////////////
for(i=0;i<unique;i++)
  printf("%d\t",arr[i]);
printf("\n\n");
return 0;
}
