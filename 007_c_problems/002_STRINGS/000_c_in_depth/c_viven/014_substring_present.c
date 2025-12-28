//Write a C program to check whether a substring is present in a string
//
#include<stdio.h>

int is_substring_present(const char* str,const char* sub){


	int i,j;


	if(*sub == '\0'){
		return 1; //null is present in str
	}



    for (i = 0; str[i] != '\0'; i++)
    {
        j = 0;

        while (str[i + j] != '\0' && sub[j] != '\0' && str[i + j] == sub[j])
        {
            j++;  //entes scope only when str[i+j] == sub[j]
        }

        if (sub[j] == '\0')
            return 1;   // full match found
    }

    return 0;   // not found








}
int main(){

	 char str[] = "EmbeddedSystems";
	 char sub[] = "pSystems";

	int present=is_substring_present(str,sub);
	if(present){
		printf("substring is present\n");
	}else{
		printf("substring is not present\n");
	
	}

return 0;
}
