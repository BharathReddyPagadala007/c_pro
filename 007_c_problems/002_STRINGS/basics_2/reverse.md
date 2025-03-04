
### 1. **Reverse a String**

```c
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[] = "hello";
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
```

### 2. **Reverse Words in a String**

```c
#include <stdio.h>
#include <string.h>

void reverseWords(char *str) {
    int length = strlen(str);
    int start = 0, end = length - 1;

    // Reverse the whole string
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }

    // Reverse each word
    start = end = 0;
    while (str[end] != '\0') {
        while (str[end] != ' ' && str[end] != '\0') end++;
        int wordEnd = end - 1;
        while (start < wordEnd) {
            char temp = str[start];
            str[start++] = str[wordEnd];
            str[wordEnd--] = temp;
        }
        start = ++end;
    }
}

int main() {
    char str[] = "Hello World";
    reverseWords(str);
    printf("Reversed words: %s\n", str);
    return 0;
}
```

### 3. **Reverse Each Word Individually**

```c
#include <stdio.h>
#include <string.h>

void reverseWord(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverseEachWord(char *str) {
    char *wordStart = NULL;
    char *temp = str;

    while (*temp) {
        if ((wordStart == NULL) && (*temp != ' ')) {
            wordStart = temp;
        }
        if (wordStart && (*(temp + 1) == ' ' || *(temp + 1) == '\0')) {
            reverseWord(wordStart, temp);
            wordStart = NULL;
        }
        temp++;
    }
}

int main() {
    char str[] = "Hello World";
    reverseEachWord(str);
    printf("Reversed each word: %s\n", str);
    return 0;
}
```

### 4. **Reverse Words and Characters**

```c
#include <stdio.h>
#include <string.h>

void reverseString(char *str, int length) {
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

void reverseWordsAndCharacters(char *str) {
    int length = strlen(str);
    reverseString(str, length);

    int start = 0, end = 0;
    while (end <= length) {
        if (str[end] == ' ' || str[end] == '\0') {
            reverseString(str + start, end - start);
            start = end + 1;
        }
        end++;
    }
}

int main() {
    char str[] = "Hello World";
    reverseWordsAndCharacters(str);
    printf("Reversed words and characters: %s\n", str);
    return 0;
}
```

### 5. **Reverse a String Using Recursion**

```c
#include <stdio.h>
#include <string.h>

void reverseRecursively(char *str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseRecursively(str, start + 1, end - 1);
}

int main() {
    char str[] = "recursion";
    reverseRecursively(str, 0, strlen(str) - 1);
    printf("Reversed string (recursively): %s\n", str);
    return 0;
}
```

### 6. **Reverse a String In-Place**

```c
#include <stdio.h>

void reverseInPlace(char *str, int length) {
    int start = 0, end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start++] = str[end];
        str[end--] = temp;
    }
}

int main() {
    char str[] = {'H', 'e', 'l', 'l', 'o'};
    int length = sizeof(str) / sizeof(str[0]);
    reverseInPlace(str, length);
    printf("Reversed in place: ");
    for (int i = 0; i < length; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
```

### 7. **Reverse Vowels in a String**

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void reverseVowels(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (start < end) {
        while (start < end && !isVowel(str[start])) start++;
        while (start < end && !isVowel(str[end])) end--;
        if (start < end) {
            char temp = str[start];
            str[start++] = str[end];
            str[end--] = temp;
        }
    }
}

int main() {
    char str[] = "hello";
    reverseVowels(str);
    printf("Reversed vowels: %s\n", str);
    return 0;
}
```

