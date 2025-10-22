//Write a program in C to find the length of a string without using library functions
//
#include<stdio.h>
#include<string.h>




int main(){
  char str[30];

  printf("enter str\n");
  scanf("%s",str);

  int len=0;
  int i=0;


  while(str[i]!='\0'){
  len++;
  i++;
  }

  printf("\n");
  printf("strlen is %d\n",len);
  printf("\n");

return 0;
}
