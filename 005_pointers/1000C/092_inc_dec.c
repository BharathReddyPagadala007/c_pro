#include<stdio.h>


void main()
 {
 int i=7;
 i = i++*i++; //56
 printf("%d\n",i);
 printf("--------------------\n");
 i=7;
 printf("%d %d\n",i ,i++*i++); // 9, 56
 printf("--------------------\n");
 i=2;
 printf("%d %d\n" ,i,   i++*++i*i++*i++); // 6,160
 printf("--------------------\n");
 i=1;
 printf("%d %d %d\n", i,    i++*i++,     i++*i++*++i*i++);
 printf("--------------------\n");
 i=1;
 printf("%d %d %d\n" ,i,    i++*i++,    i++*i++*++i*i++*i++*++i);
 printf("--------------------\n");
 }
