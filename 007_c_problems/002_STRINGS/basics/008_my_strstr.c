/*
 Implement strstr Function
Write your own version of the strstr function to find the first occurrence of a substring in a string.
Example:
Input: "hello world", "world"
Output: Pointer to "world" (start of the substring in the original string)
*/
////////////////////////////////
#include<stdio.h>
#include<string.h>


int main()
{
  char * str = "hello world this is fpga time but needs to master mcu first... cand then verilog";
  char * sub_str = "fpga";
  int len = strlen(str);
  int sublen = strlen(sub_str);
  int i,j;

  for(i=0;i<len;i++)
  {
	  for(j=0;j<sub_len;j++)
	  {
      		if(*(str+i)!=*(sub_str+j))	  
		{
                    break;		  
		
		}

	  }
  }



return 0;
}
////////////////////////////
/*
 * #include <stdio.h>

char* my_strstr(const char* haystack, const char* needle) {
    // If needle is an empty string, return the haystack
    if (*needle == '\0') {
        return (char*)haystack;
    }

    // Iterate over each character in the haystack
    for (const char* h = haystack; *h != '\0'; h++) {
        // Check if the first character matches
        if (*h == *needle) {
            // Pointer to iterate over the current match in haystack
            const char* h_sub = h;
            // Pointer to iterate over needle
            const char* n = needle;

            // Check subsequent characters
            while (*h_sub == *n && *n != '\0') {
                h_sub++;
                n++;
            }

            // If we reached the end of the needle, we found a match
            if (*n == '\0') {
                return (char*)h;
            }
        }
    }

    // No match found
    return NULL;
}

int main() {
    const char* haystack = "Hello, world!";
    const char* needle = "world";

    char* result = my_strstr(haystack, needle);
    if (result != NULL) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
*/
