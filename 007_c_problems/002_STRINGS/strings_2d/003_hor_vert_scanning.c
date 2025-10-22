#include<stdio.h>
#include<string.h>


int main(){

	char str[5][10] = {
		"white",
		"green",
		"red",
		"yellow",
		"blue"
	};

	int n = sizeof(str)/sizeof(str[0]);

	for(int i=0; i<n; i++){
		printf("%s \n",str[i]);
	
	}


	printf("horiontal scanbning\n----------------------------------------------\n");
	for(int row=0; row<n; row++){
		for(int col=0; col<strlen(str[row]);col++){
			printf("%c ",str[row][col]);
		
		
		}
		printf("\n");
	}
	printf("vertical scanning\n---------------------------------------------\n");

	for(int col=0;  col<10 ; col++){
	
		for(int row=0; row<n; row++){
			if(str[row][col]=='\0'){

				printf("--");

			}else{
			
			printf("%c ",str[row][col]);
			}
		
		
		}
		printf("\n");
	
	}

return 0;
}
