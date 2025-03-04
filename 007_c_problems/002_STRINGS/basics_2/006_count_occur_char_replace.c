//count(char str[],char ch);
//replace(char str[], char ch, char new);
//
// old char == t
// new char == m
//  bharth tailung
/////////////////////////////
#include<stdio.h>
#include<string.h>

int count(char str[],char ch);
void replace(char str[], char ch, char new);
int main()
{
 char str[50];
 char ch = 't';
 strcpy(str, "bharath tailung");
 puts(str);
 printf("%d-->count of char  %c\n",count(str,ch),ch);
 replace(str, 't','m' );
 puts(str);
return 0;
}

int count(char str[],char ch)
{
   int cnt=0;
   while(*str++ != '\0')
   {
	if(*str == ch)     cnt++;
   }
return cnt;
}
void replace(char str[], char ch, char new)
{
   while(*str++ != '\0')
   {
       if(*str == ch)
       {
         *str = new;
       }
   }
}
