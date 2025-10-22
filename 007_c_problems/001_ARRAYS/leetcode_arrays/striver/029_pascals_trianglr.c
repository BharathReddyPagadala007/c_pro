/*
https://leetcode.com/problems/pascals-triangle/description/
*/

#include<stdio.h>



//
//--------------------------------------------------------------
int main(){


	int arr[5][5];
	int r=5;
	int c=5;



	for(int i=0; i<5; i++){
		for(int j=0; j<=i; j++){
			if(i==j || j==0 )
			{
				arr[i][j]=1;


			}else{
				arr[i][j]=arr[i-1][j]+arr[i-1][j-1];

			}
			printf("%d ",arr[i][j]);
		}

		printf("\n");
	}
return 0;
}
