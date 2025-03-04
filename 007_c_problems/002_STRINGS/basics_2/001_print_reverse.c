//
//program to enter a string and print it in reverse order
//


#include<stdio.h>
#include<string.h>

int main()
{
  char str[50];
  int len;

  printf("enter aqstring \n");
  scanf("%s",str);

  printf("str = %s \n",str);


  ////////////////////
  //reverse order
  //
  //
     printf("reverse ==  ");
  for( int i =strlen(str)-1;i >=0 ; i--)
  {
     printf(" %c ",*(str + i));
  }
return 0;
}
