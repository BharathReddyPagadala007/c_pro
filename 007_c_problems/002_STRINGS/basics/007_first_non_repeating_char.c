/*
Find the First Non-Repeating Character
Write a function to find the first character in a string that does not repeat.
Example:
Input: "swiss"
Output: "w"
*/

#include<stdio.h>
#include<string.h>


int main()
{
  char str[]= "swisserland";
  int len= strlen(str);
  int i,j;
  int freq[len];
  /////////////////////////////////////////////////////////

  for(i=0;i<len-1;i++)
  {
 //   select an elemenyt and check if it  repeats  
      
	  for(j=0;j<len -1;j++)
	  {
	  
	    if((str[i]== str[j]))
	    {
		    freq[i]++;
	    }

	  }
  
  }
  /////////////////////////////////////////////////////////
	  for(int i=0;i< len -1; i++)
	  {
	    if(freq[i]==1)
	    {
	    printf("non repeating element index =%d,char =%c\n",i,str[i]);
	    }
	  }

  /////////////////////////////////////////////////////////
  
  

return 0;
}
