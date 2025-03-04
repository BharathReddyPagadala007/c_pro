#include <stdio.h>

// Function prototypes
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0)
        return a / b;
    else
        return 0; // Return zero to avoid division by zero
}

int main() {
int (* operations[4])(int,int)= {add, subtract, multiply, divide};
int choice, a=10, b=5;

printf("choose an operation  \n0: add\n1:sub\n2:mult\n3:divide\n");
scanf("%d",&choice);


if(choice >=0 && choice <4)
{
  int result = operations[choice](a,b);
  printf("result: %d\n",result);
}
else{
printf("invalid choice \n");
}

    return 0;
}

