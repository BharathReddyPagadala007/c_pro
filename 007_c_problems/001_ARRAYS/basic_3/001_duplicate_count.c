#include<stdio.h>


///////////////////////////////////////////////////////////
//
//  there are duplicates in this array 
//  count  how many
//
//
///////////////////////////////////////////////////////////

int main()
{

	int arr[10]={1,2,3,4,5,5,6,3,2,1};


	int i,j;
	int count=0;

	for(i=0;i<10;i++)
	{
         
	 for(j=i+1;j<10;j++)
	 {
		 if(arr[i]==arr[j])
	         {
			 count++;
			 printf("%d ",arr[i]);
			 break;
		 }

	 
	 }
	
	}
	printf("count == %d\n",count);
	printf("\n");
return 0;
}
