//  top = MAX -1
//
//
//   top = 0
//   ----------------
//   top = -1 
/////////////////////////O
#include<stdio.h>




//DEFINE
#define MAX 10
//GLOBAL VAR
int stack[MAX];
int top=-1;


// stack implementation functions
void push();
void pop();
void display();

// main
int main()
{


  push(10);
  push(20);
  push(30);
  display();
  printf("----------------\n");
  pop();
  display();


}
void push(int value)
{

    // if full cant push 
    
	//where to store it should be in stack  but what vbariable keeps track of which index of stack to enters i
	//its top value if its == max its full if its -1 its empty and upon each push top value gets incrementaed 
	//so now the question is should ++top or  top++ it depends the initial value of top and what u define as full
	
  if(top == MAX -1)
  {
    printf("the stack is empty cant push  -->%d cant be pushed\n", value);
  }
  else
  {
    stack[++top]= value;
  }

//there is nothing to return the 
}
/////////////////////////////////////////
void display()
{
	int i;
	if(top == -1)
	{
	 printf("stack si empty \n");
	
	}
	else{
  for(i=0;i<= top ;i++) //condition is top not MAX -1 as it is meant to print only upto elements that existing
  {
    printf("%d\n",stack[i]); 
  
  }}

}
/////////////////////////////////////
void pop()
{
  if(top == -1)
  {
   printf("empty a\n");
  }
  else
  {
	 top--;
    printf("an element is popped\n");
  }


}
