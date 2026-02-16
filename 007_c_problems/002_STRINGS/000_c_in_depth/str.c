/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char* astrcpy(char* str1, char* str2){
    while(*str2!='\0'){
        *str1++= *str2++;
    };
   // printf("swap done %s , %s\n====\n",str1,str2);
    
    return str1;
    
}

void swap_str(char* str1, char* str2){
    
    char * temp
    
   astrcpy(temp,str1);
   astrcpy(str1,str2);
   astrcpy(str2,temp);
   //printf("swap done %s , %s\n====\n",str1,str2);
   
    
}
int main()
{
    char  str[5][20] = {"mango","grapes","banana","apple"};
 
    
      //swap_str(str[0],str[1]);
      
    for(int i=0;i<3;i++){
      for(int j=i+1;j<=3;j++){
      if(str[i][0] >str[j][0]){
          swap_str(str[i],str[j]);
          
      }
      }
    }
    
    
    for(int k=0; k<4; k++){
        printf("%s ",str[k]);
    }

    return 0;
}
