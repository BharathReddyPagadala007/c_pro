#include<stdio.h>
#include<string.h>

int main()
{
	char* strs[] = {"flower", "flow", "flight","first","flavor"};

    int strs_len  = sizeof(strs) / sizeof(strs[0]);


    int row, col;
    int i;

for(i=0;i<strs_len;i++){
    printf("strs[%d]= %s--sizeof(strs[%d])==%ld \t---strlen(strs[%d])-->%ld--%p\n",i,strs[i],i,sizeof(strs[i]),i,strlen(strs[i]),strs[i]);
    // r-h ,, c-v
}
/////////////////////////////////////////////////////////////
printf("===================================================================\n");
    for(row=0; row<strs_len; row++){
	 for(col=0; col < strlen(strs[row]); col++){
                  printf("strs[%d][%d] = %c  ", row, col, strs[row][col]);
	    }
	    printf("\n");
    }

printf("===================================================================\n");
int max_len_str=strlen(strs[0]);

for(i=0; i<strs_len; i++){

	if(strlen(strs[i])>max_len_str){
	max_len_str= strlen(strs[i]);
	}
}
    for(col=0; col<max_len_str; col++){
	 for(row=0; row < strs_len; row++){
		 if(strs[row][col]!='\0'){
                  printf("strs[%d][%d] = %c  ", row, col, strs[row][col]);
		 }else{
		 printf("strs[%d][%d]==nullll",row,col);
			 break;
		 }
	    }
	    printf("\n");
    }

printf("===================================================================\n");
/////////////////////////////////////////////////////////////
return 0;
}
