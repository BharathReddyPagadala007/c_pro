
### 1. `strlen()`
Calculates the length of a string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, world!";
    size_t length = strlen(str);
    printf("Length of the string is: %zu\n", length);
    return 0;
}
```

### 2. `strcpy()` and `strncpy()`
Copies one string to another.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    // Using strcpy
    strcpy(dest, src);
    printf("Copied string using strcpy: %s\n", dest);

    // Using strncpy (copying only 5 characters)
    strncpy(dest, src, 5);
    dest[5] = '\0'; // Null-terminate the string
    printf("Copied string using strncpy: %s\n", dest);

    return 0;
}
```

### 3. `strcat()` and `strncat()`
Appends one string to another.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char dest[30] = "Hello";
    char src[] = ", world!";

    // Using strcat
    strcat(dest, src);
    printf("Concatenated string using strcat: %s\n", dest);

    // Resetting dest
    strcpy(dest, "Hello");

    // Using strncat (appending only 5 characters)
    strncat(dest, src, 5);
    printf("Concatenated string using strncat: %s\n", dest);

    return 0;
}
```

### 4. `strcmp()` and `strncmp()`
Compares two strings lexicographically.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello, world!";

    // Using strcmp
    int result = strcmp(str1, str2);
    printf("Comparison result using strcmp: %d\n", result);

    // Using strncmp (comparing only first 5 characters)
    result = strncmp(str1, str2, 5);
    printf("Comparison result using strncmp: %d\n", result);

    return 0;
}
```

### 5. `strchr()` and `strrchr()`
Finds the first or last occurrence of a character in a string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    char ch = 'o';

    // Using strchr
    char *firstOccurrence = strchr(str, ch);
    if (firstOccurrence) {
        printf("First occurrence of '%c': %s\n", ch, firstOccurrence);
    }

    // Using strrchr
    char *lastOccurrence = strrchr(str, ch);
    if (lastOccurrence) {
        printf("Last occurrence of '%c': %s\n", ch, lastOccurrence);
    }

    return 0;
}
```

### 6. `memcpy()` and `memmove()`
Copies memory blocks.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char src[] = "Hello, world!";
    char dest[20];

    // Using memcpy
    memcpy(dest, src, strlen(src) + 1);
    printf("Copied string using memcpy: %s\n", dest);

    // Using memmove (for overlapping memory)
    char overlap[] = "Hello, world!";
    memmove(overlap + 6, overlap, strlen("Hello") + 1);
    printf("Result after memmove: %s\n", overlap);

    return 0;
}
```

### 7. `strtok()`
Tokenizes a string using a delimiter.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This is C programming.";
    char *token;

    // Using strtok to split the string by spaces
    token = strtok(str, " ");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
```

### 8. `strstr()`
Finds the first occurrence of a substring in a string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char haystack[] = "Hello, world! Welcome to C programming.";
    char needle[] = "world";

    // Using strstr
    char *found = strstr(haystack, needle);
    if (found) {
        printf("Substring found: %s\n", found);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
```

### 9. `strerror()`
Returns a pointer to the error message string corresponding to an error number.
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (!file) {
        // Using strerror to print the error message
        printf("Error opening file: %s\n", strerror(errno));
    }
    return 0;
}
```

### 10. `strspn()` and `strcspn()`
Calculates the length of the initial segment consisting of characters in or not in a set.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "abc12345def";
    char accept[] = "abc123";

    // Using strspn
    size_t len = strspn(str, accept);
    printf("Length of initial segment matching: %zu\n", len);

    // Using strcspn
    len = strcspn(str, "45");
    printf("Length of initial segment not containing '45': %zu\n", len);

    return 0;
}
```

### 11. `strpbrk()`
Finds the first occurrence of any character from one string in another string.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "aeiou";

    // Using strpbrk
    char *found = strpbrk(str1, str2);
    if (found) {
        printf("First vowel found: %c\n", *found);
    } else {
        printf("No vowels found.\n");
    }

    return 0;
}
```

### 12. `strdup()` and `strndup()`
Duplicates a string. `strdup` duplicates the entire string, while `strndup` duplicates up to `n` characters.
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[] = "Hello, world!";

    // Using strdup
    char *dup = strdup(str);
    if (dup) {
        printf("Duplicated string using strdup: %s\n", dup);
        free(dup); // Don't forget to free the allocated memory
    }

    // Using strndup
    char *ndup = strndup(str, 5);
    if (ndup) {
        printf("Duplicated string using strndup: %s\n", ndup);
        free(ndup); // Free the allocated memory
    }

    return 0;
}
```

### 13. `memcmp()`
Compares the first `n` bytes of two memory blocks.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char mem1[] = "Hello, world!";
    char mem2[] = "Hello, Earth!";

    // Using memcmp
    int result = memcmp(mem1, mem2, 5);
    if (result == 0) {
        printf("The first 5 bytes are identical.\n");
    } else {
        printf("The first 5 bytes are different.\n");
    }

    return 0;
}
```

### 14. `memset()`
Fills a block of memory with a specified value.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[20] = "Hello, world!";

    // Using memset to set the first 5 characters to '*'
    memset(str, '*', 5);
    printf("Modified string: %s\n", str);

    return 0;
}
```

