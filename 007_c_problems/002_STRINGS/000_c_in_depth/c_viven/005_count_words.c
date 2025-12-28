//
//
//
//Write a program in C to count the total number of words in a string. 
//
//
//
#include<stdio.h>
#include<string.h>
#include<ctype.h>



int count_words(char * str)
{
   int count = 0;

   while(*str!= '\0')
   {
     // while it is space until its end str++
     // if there is a non space char it is time to str++
     while(isspace(*str))
     {  str++;
     }

  Write a program in C to count the total number of words in a string.    if(*str == '\0'){   return count; }

     while( !isspace(*str) && *str != '\0')
     {
       //putchar(*str);
       str++;                                                                                                                                  
     }                                                                                                                                         
     count++;                                                                                                                                  
     printf("\n");                                                                                                                             
                                                                                                                                               
   }//while                                                                                                                                    
return count;                                                                                                                                  
}      


int main(){

char 	str[] = "bharath reddy pagadala";
char* 	str1  = "iam going to movie";
char 	str2[20] ;  // array size should be mentioned
char*   str3;
//=================================
printf("str2\n");
gets(str2);
//puts(str2);


printf("str3\n");
gets(str3);
//puts(str3);

//=================================
int count =0;

count =count_words(str);
printf("-->%d\n",count);
count =count_words(str1);
printf("-->%d\n",count);
count =count_words(str2);
printf("-->%d\n",count);
count =count_words(str3);
printf("-->%d\n",count);


return 0;

}
