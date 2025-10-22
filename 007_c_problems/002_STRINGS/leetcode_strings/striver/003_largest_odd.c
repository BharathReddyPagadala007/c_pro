#include <stdio.h>
#include <string.h>

char* largestOddNumber(char* num) {
   int n = strlen(num);
    
  for(int i=n; i>=0; i--){
      if((num[i]-'0')%2 ==1){
          num[i+1]='\0';
          return num;
      }
      
  }
  return "";
    
}

int main() {
    char num1[] = "35427";
    char num2[] = "4206";
    printf("Largest odd number in %s: %s\n", num1, largestOddNumber(num1));
    printf("Largest odd number in %s: %s\n", num2, largestOddNumber(num2));
    return 0;
}

