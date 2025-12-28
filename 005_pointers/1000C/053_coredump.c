#include<stdio.h>


main(){
int a,b; 
printf("enter two numbers :"); 
scanf("%d %d",a,b);// format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘int
//scanf("%d %d",&a,&b); 
printf("%d+%d=%d",a,b,a+b); 
}
