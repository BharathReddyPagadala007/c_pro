
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char  str[20];
    char* p ;

    
    int i=0;
    printf("enter string :: \n");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]= '\0';
    printf("ur string :: -->>>> %s \n",str);
    
    /*
    while(str[i]!='\0'){
        
        
        printf("%c  \n",str[i]);
	i++;
        
    }
    */


    // pointer version
    //
    //
    for(p= str;  *p!= '\0'; p++ ){
      printf("%c \n",*p);
    
    }
    printf("\n");

    return 0;
}//Write a program in C to separate individual characters from a string.


// what is difference between strspn , strcspn;
//
//
//


