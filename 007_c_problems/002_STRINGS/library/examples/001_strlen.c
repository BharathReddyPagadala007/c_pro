#include<stdio.h>
#include<string.h>


int main()
{
  char str[50];
  printf("enter a string: \n");
  gets(str);

  printf("lengthe of string :%ld\n",strlen(str));


return 0;
}



/*
 *
$ ./a.out 
enter a string: 
bharath reddy pagadala lnux rtos freertos fpga tanga nano 9k beaglke bone black raspberry pi
lengthe of string :92
*** stack smashing detected ***: terminated
Aborted (core dumped)
*/
