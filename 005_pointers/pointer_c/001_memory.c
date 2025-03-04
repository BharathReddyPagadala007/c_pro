#include<stdio.h>

int main()
{

int p = 5;
int * pi ;
pi =&p;

int size;


printf("p=   %d\n",p);
printf("&p=  %p\n",&p);
printf("pi=  %p-----sizeof pointer=%ld\n",pi,sizeof(pi));
printf("&pi= %p\n",&pi);

}

