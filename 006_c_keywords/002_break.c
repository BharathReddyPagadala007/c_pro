/*Important Points
The break statement only affects the nearest enclosing loop or switch statement.
If break is used in nested loops, it will only exit the innermost loop.
It's often used with conditional statements to make loop termination based on specific criteria.
 * */
///////////////////////////////////////////////
//
//  BREAK	
//
#include<stdio.h>

int main()
{

	int i,j;

	for(i=0;i<=5;i++)
	{
		for(j=0;j<=5;j++)
		{ 
			//printf("i=%d,j=%d\n",i,j);

		if(j==3)
		  {
			  break;
		  }

	  	printf("----------------------------------------------inside j loop---%d==j\n",j);

		}
		printf("====%d==\n",i);
	}

return 0;
}
