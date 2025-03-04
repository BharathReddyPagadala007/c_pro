/*
Rotate a String by N Positions
Rotate a given string by N positions to the left or right.
Example:
Input: "hello", N = 2 (left rotation)
Output: "llohe"
*/
///////////////////////////////////////
#include<string.h>
#include<stdio.h>
void rotate_left( char* str, int N);   // N positions
void reverse(char * str, int start, int end);
int main()
{
   char * str= "hello";
   int len = strlen(str);

   rotate_left(str,2);

return 0;
}
void rotate_left( char * str, int N)
{

int  len= strlen(str);
   N = N % len;

   reverse(str,0,N -1);
   reverse(str, N, len -1);
   reverse(str, 0 , len -1);




}
void reverse(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

