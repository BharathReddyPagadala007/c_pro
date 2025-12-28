
//Write a program in C to print individual characters of a string in reverse order. 
#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char  str[20];

    char* p;
    
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

    printf("reverse order:::--->>> \n");


    for(i=strlen(str)-1;   i>=0;  i--){
	    printf("%c \n",str[i]);
    
    }
    printf("\n");



    printf("reverse order pointer version ::\n");

   
    p = str;

 
    while(*p!= '\0'){
    p++;
    }
    p--;

    while(p>=str){
    
    printf("%c\n",*p);
    p--;
    }



    return 0;
}


// what is difference between strspn , strcspn;
//
//
//


