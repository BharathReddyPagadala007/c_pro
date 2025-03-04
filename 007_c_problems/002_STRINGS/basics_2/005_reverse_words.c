//reverse_letters()
//  i have many books
//  i evah ynam skoob

void reverse_letters(char str[], int start , int end);
void reverse(char str[], int start , int end);
void reverse_words(char str[], int start, int end);

#include<stdio.h>
#include<string.h>
int main()
{
   char str[50];
   strcpy(str, "i have many books");
   reverse_words(str, 0, strlen(str)-1);
   puts(str);
return 0;
}
void reverse_letters(char str[], int start , int end)
{
    int w_start  ,w_end;
    int i;
    for(w_start=w_end=start; w_end<end; w_end++)
    {
         if(str[w_end] == ' ')  
		 continue;
	 w_start = w_end;
	 while(str[w_end] != ' ' &&    w_end <= end)
		 w_end++;
	 w_end--;
	 reverse(str,w_start,w_end);
    }
}
void reverse(char str[], int start , int end)
{
  char temp;
  while(start <= end)
  {
    temp =str[start];
    str[start]= str[end];
    str[end]= temp;
    start++;
    end--;
  }
}

void reverse_words(char str[], int start, int end)
{
   reverse(str, start, end);
   reverse_letters(str,start, end);
}
