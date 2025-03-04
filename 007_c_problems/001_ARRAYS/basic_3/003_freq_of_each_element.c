#include<stdio.h>


int main()
{

	int n;
	int count;
	int i,j;

	printf("number of elkements \n");
	scanf("%d",&n);

	int arr[n],freq[n];

	for(i=0;i<n;i++)
	{
	   printf("enter %d elemnt \n",i);
	   scanf("%d",&arr[i]);
	   freq[i]=-1;
	
	}


	for(i=0;i<n;i++)
	{
		
	  count =1;

	  for(j=i+1;j<n;j++)
	  {
	    if(arr[i]==arr[j])
	    {
	      count++;
	      freq[j]=0;
	    }
	  }

	  if(freq[i]!=0)
	  {
	   freq[i]=count;
	  
	  }
	  
	
	}

	printf("====================\n");


	for(i=0;i<n;i++)
	{
	
		if(freq[i]!=0)
		{
			printf("%d --> %d-->%d\n",i,arr[i],freq[i]);

	
		}
	}


}
