
#include <stdio.h>
#include<string.h>


void reverse(char* str,int start, int end);
void reverse_words(char* str,int start, int end);


int main() {
    
    char str[] = "   hyderabad is a city   ";
    int len = strlen(str);
    char * sptr;
    
    
         reverse(str,0,len-1);
        
        printf("\n%s \n",str);
        
            reverse_words(str,0,len-1);
          printf("\n%s \n",str);
        
         return 0;
}


void reverse(char* str,int start, int end){
    
  while(start<=end){
      char temp =str[start];
      str[start]= str[end];
      str[end] = temp;
      start++;
      end--;
  }
  
    
}


//------------------------------
void reverse_words(char* str,int start, int end){
    
    int w_start,w_end;
    
 for(w_start=w_end=start; w_end<end; w_end++){
   if(str[w_end] == ' '){
        continue;
    }
    
    w_start= w_end;
    
    while(str[w_end]!=' ' && w_end<end){
        w_end++;
    }
    w_end--;
    
    reverse(str,w_start,w_end);
 }

    
}

