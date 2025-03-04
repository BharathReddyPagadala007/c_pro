### 1. Pointer Basics

**a. Declare an integer variable and a pointer to it. Assign a value to the variable and print its value using both the variable and the pointer.**
   - **Objective**: Understand how to use pointers to reference the memory address of a variable.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         int num = 42;      // Declare an integer variable
         int *ptr = &num;  // Declare a pointer to the variable

         printf("Value of num: %d\n", num);         // Using variable
         printf("Value using pointer: %d\n", *ptr); // Using pointer

         return 0;
     }
     ```
   - **Explanation**: The `&` operator is used to get the address of `num`, which is stored in `ptr`. The `*` operator dereferences the pointer to get the value it points to.

**b. Create a program to swap two integer variables using pointers.**
   - **Objective**: Learn how to modify variables indirectly using pointers.
   - **Code**:
     ```c
     #include <stdio.h>

     void swap(int *a, int *b) {
         int temp = *a; // Store the value at pointer a in temp
         *a = *b;       // Assign the value at pointer b to a
         *b = temp;     // Assign temp (original value of a) to b
     }

     int main() {
         int x = 5, y = 10;
         printf("Before swap: x = %d, y = %d\n", x, y);
         swap(&x, &y); // Pass addresses of x and y
         printf("After swap: x = %d, y = %d\n", x, y);
         return 0;
     }
     ```
   - **Explanation**: The function `swap` takes two integer pointers and swaps their values by dereferencing the pointers.

### 2. Pointer Arithmetic

**a. Implement a program to demonstrate pointer arithmetic by incrementing and decrementing a pointer to an array.**
   - **Objective**: Understand how pointer arithmetic works with arrays.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         int arr[] = {10, 20, 30, 40, 50};
         int *ptr = arr; // Pointer to the first element

         printf("Using pointer arithmetic:\n");
         for (int i = 0; i < 5; i++) {
             printf("Element %d: %d\n", i, *(ptr + i)); // Access using pointer
         }

         return 0;
     }
     ```
   - **Explanation**: Here, we increment the pointer `ptr` to access each element of the array. `*(ptr + i)` gives the value of the element at index `i`.

**b. Write a program to find the sum of elements in an array using a pointer.**
   - **Objective**: Use pointers to traverse an array and calculate the sum.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         int arr[] = {1, 2, 3, 4, 5};
         int sum = 0;
         int *ptr = arr;

         for (int i = 0; i < 5; i++) {
             sum += *(ptr + i); // Add each element to sum
         }

         printf("Sum of array elements: %d\n", sum);
         return 0;
     }
     ```
   - **Explanation**: The program uses a pointer to iterate through the array and calculate the sum of its elements.

### 3. Pointer to Pointer

**a. Write a program to demonstrate a pointer to a pointer (double pointer). Use it to modify the value of a variable.**
   - **Objective**: Learn about double pointers and their usage.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         int num = 10;
         int *ptr = &num;   // Pointer to num
         int **ptr2 = &ptr; // Pointer to pointer

         printf("Original value: %d\n", num);
         **ptr2 = 20; // Modify the value of num using double pointer
         printf("Modified value: %d\n", num);

         return 0;
     }
     ```
   - **Explanation**: The double pointer `ptr2` points to the pointer `ptr`, which in turn points to `num`. We can modify `num` through the double pointer.

**b. Implement a program to dynamically allocate memory for a 2D array using a double pointer.**
   - **Objective**: Understand dynamic memory allocation with double pointers.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <stdlib.h>

     int main() {
         int rows = 3, cols = 4;
         int **arr = (int **)malloc(rows * sizeof(int *)); // Allocate array of pointers
         
         for (int i = 0; i < rows; i++) {
             arr[i] = (int *)malloc(cols * sizeof(int)); // Allocate each row
         }

         // Fill the 2D array
         for (int i = 0; i < rows; i++) {
             for (int j = 0; j < cols; j++) {
                 arr[i][j] = i * cols + j + 1;
             }
         }

         // Print the 2D array
         for (int i = 0; i < rows; i++) {
             for (int j = 0; j < cols; j++) {
                 printf("%d ", arr[i][j]);
             }
             printf("\n");
         }

         // Free allocated memory
         for (int i = 0; i < rows; i++) {
             free(arr[i]);
         }
         free(arr);

         return 0;
     }
     ```
   - **Explanation**: The program uses `malloc` to allocate memory for a 2D array and fills it with values. It also demonstrates how to free the allocated memory to avoid memory leaks.

### 4. Pointer and Arrays

**a. Create a program to reverse an array using pointers.**
   - **Objective**: Use pointers to reverse the elements of an array in place.
   - **Code**:
     ```c
     #include <stdio.h>

     void reverse(int *arr, int size) {
         int *start = arr;
         int *end = arr + size - 1;
         while (start < end) {
             int temp = *start;
             *start = *end;
             *end = temp;
             start++;
             end--;
         }
     }

     int main() {
         int arr[] = {1, 2, 3, 4, 5};
         int size = sizeof(arr) / sizeof(arr[0]);

         reverse(arr, size);
         printf("Reversed array: ");
         for (int i = 0; i < size; i++) {
             printf("%d ", arr[i]);
         }
         printf("\n");

         return 0;
     }
     ```
   - **Explanation**: The function `reverse` uses two pointers: one starting at the beginning of the array and the other at the end. They swap elements until they meet in the middle.

**b. Write a program to find the length of a string using a pointer.**
   - **Objective**: Learn how to use pointers to traverse a string.
   - **Code**:
     ```c
     #include <stdio.h>

     int stringLength(char *str) {
         int length = 0;
         while (*str != '\0') { // Traverse until null terminator
             length++;
             str++;
         }
         return length;
     }

     int main() {
         char str[] = "Hello, World!";
         int length = stringLength(str);
         printf("Length of string: %d\n", length);

         return 0;
     }
     ```
   - **Explanation**: The function `stringLength` increments the pointer `str` until it reaches the null terminator, counting the characters in the process.

### 5. Pointer to Functions

**a. Implement a program that uses a pointer to a function to call different arithmetic operations (addition, subtraction, multiplication, division).**
   - **Objective**: Understand how to use function pointers to call different functions.
   - **Code**:
     ```c
     #include <stdio.h>

     // Function prototypes
     int add(int a, int b) { return a + b; }
     int subtract(int a, int b) { return a - b; }
     int multiply(int a, int b) { return a * b; }
     int divide(int a, int b) { return a / b; }

     int main() {
         int (*operation)(int, int); // Function pointer
         int a = 10, b = 5;

         operation = add; // Point to add function
         printf("Addition: %d\n", operation(a, b));

         operation = subtract; // Point to subtract function
         printf("Subtraction: %d\n", operation(a, b));

         operation = multiply; // Point to multiply function
         printf("Multiplication: %d\n", operation(a, b));

         operation = divide; // Point

 to divide function
         printf("Division: %d\n", operation(a, b));

         return 0;
     }
     ```
   - **Explanation**: The program defines several arithmetic functions and uses a function pointer to call them based on user selection or logic.

**b. Create a program that sorts an array using a function pointer to different comparison functions (ascending or descending).**
   - **Objective**: Use function pointers for sorting based on different criteria.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <stdlib.h>

     // Comparison function for ascending order
     int compareAsc(const void *a, const void *b) {
         return (*(int *)a - *(int *)b);
     }

     // Comparison function for descending order
     int compareDesc(const void *a, const void *b) {
         return (*(int *)b - *(int *)a);
     }

     void sortArray(int *arr, int size, int (*compare)(const void *, const void *)) {
         qsort(arr, size, sizeof(int), compare); // Quick sort with comparison function
     }

     int main() {
         int arr[] = {5, 3, 8, 1, 2};
         int size = sizeof(arr) / sizeof(arr[0]);

         // Sort in ascending order
         sortArray(arr, size, compareAsc);
         printf("Sorted in ascending order: ");
         for (int i = 0; i < size; i++) {
             printf("%d ", arr[i]);
         }
         printf("\n");

         // Sort in descending order
         sortArray(arr, size, compareDesc);
         printf("Sorted in descending order: ");
         for (int i = 0; i < size; i++) {
             printf("%d ", arr[i]);
         }
         printf("\n");

         return 0;
     }
     ```
   - **Explanation**: This program uses the `qsort` function from the standard library, which accepts a comparison function pointer to sort the array either in ascending or descending order.

### 6. Dynamic Memory Allocation

**a. Write a program to allocate memory dynamically for an array of integers using `malloc` and fill it with values.**
   - **Objective**: Learn how to allocate and deallocate memory dynamically.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <stdlib.h>

     int main() {
         int size;
         printf("Enter size of array: ");
         scanf("%d", &size);

         int *arr = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory
         if (arr == NULL) {
             printf("Memory allocation failed!\n");
             return 1; // Exit if allocation fails
         }

         // Fill the array with values
         for (int i = 0; i < size; i++) {
             arr[i] = i + 1; // Assign values
         }

         // Print the array
         printf("Array elements: ");
         for (int i = 0; i < size; i++) {
             printf("%d ", arr[i]);
         }
         printf("\n");

         free(arr); // Free allocated memory
         return 0;
     }
     ```
   - **Explanation**: This program dynamically allocates memory for an integer array based on user input. It fills the array with values and then frees the allocated memory.

**b. Create a program to read a string from the user, dynamically allocate memory for it, and print the string.**
   - **Objective**: Understand dynamic memory allocation for strings.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <stdlib.h>

     int main() {
         char *str = (char *)malloc(100 * sizeof(char)); // Allocate memory for string
         if (str == NULL) {
             printf("Memory allocation failed!\n");
             return 1; // Exit if allocation fails
         }

         printf("Enter a string: ");
         fgets(str, 100, stdin); // Read string input

         printf("You entered: %s", str);
         free(str); // Free allocated memory

         return 0;
     }
     ```
   - **Explanation**: The program allocates memory for a string, reads input using `fgets`, and then prints the string before freeing the allocated memory.

### 7. Pointer to Structures

**a. Define a structure for a `Person` with fields `name`, `age`, and `height`. Create a program to input data for a `Person` using pointers.**
   - **Objective**: Learn to use pointers with structures.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <string.h>

     struct Person {
         char name[50];
         int age;
         float height;
     };

     int main() {
         struct Person person;
         struct Person *ptr = &person; // Pointer to the structure

         printf("Enter name: ");
         fgets(ptr->name, sizeof(ptr->name), stdin); // Using pointer to access fields
         ptr->name[strcspn(ptr->name, "\n")] = 0; // Remove newline character

         printf("Enter age: ");
         scanf("%d", &ptr->age); // Using pointer to access fields

         printf("Enter height: ");
         scanf("%f", &ptr->height); // Using pointer to access fields

         printf("Person Details:\n");
         printf("Name: %s\n", ptr->name);
         printf("Age: %d\n", ptr->age);
         printf("Height: %.2f\n", ptr->height);

         return 0;
     }
     ```
   - **Explanation**: The program defines a `Person` structure and uses a pointer to access its fields for input and output.

**b. Implement a program to dynamically allocate memory for an array of structures and fill it with user-provided data.**
   - **Objective**: Use dynamic memory allocation with structures.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <stdlib.h>
     #include <string.h>

     struct Person {
         char name[50];
         int age;
         float height;
     };

     int main() {
         int n;
         printf("Enter number of persons: ");
         scanf("%d", &n);
         struct Person *persons = (struct Person *)malloc(n * sizeof(struct Person)); // Allocate memory

         for (int i = 0; i < n; i++) {
             printf("Enter details for person %d:\n", i + 1);
             printf("Name: ");
             scanf("%s", persons[i].name); // Using array indexing
             printf("Age: ");
             scanf("%d", &persons[i].age);
             printf("Height: ");
             scanf("%f", &persons[i].height);
         }

         // Print the details of persons
         for (int i = 0; i < n; i++) {
             printf("Person %d - Name: %s, Age: %d, Height: %.2f\n", 
                     i + 1, persons[i].name, persons[i].age, persons[i].height);
         }

         free(persons); // Free allocated memory
         return 0;
     }
     ```
   - **Explanation**: This program dynamically allocates memory for an array of `Person` structures, takes input for each person's details, and then prints them.

### 8. Pointer and Strings

**a. Write a program to copy one string to another using pointers.**
   - **Objective**: Learn how to manipulate strings using pointers.
   - **Code**:
     ```c
     #include <stdio.h>

     void stringCopy(char *dest, const char *src) {
         while (*src != '\0') { // Copy until null terminator
             *dest = *src;
             dest++;
             src++;
         }
         *dest = '\0'; // Add null terminator to destination string
     }

     int main() {
         char source[] = "Hello, World!";
         char destination[50]; // Allocate enough space

         stringCopy(destination, source); // Copy string
         printf("Copied string: %s\n", destination);

         return 0;
     }
     ```
   - **Explanation**: The function `stringCopy` iterates through the source string and copies each character to the destination until it reaches the null terminator.

**b. Create a program to compare two strings using pointers without using any standard library functions.**
   - **Objective**: Understand how to compare strings using pointers.
   - **Code**:
     ```c
     #include <stdio.h>

     int stringCompare(const char *str1, const char *str2) {
         while (*str1 != '\0' && *str2 != '\0') {
             if (*str1 != *str2) {
                 return *str1 - *str2; // Return the difference
             }
             str1++;
             str2++;
         }
         return *str1 - *str2; // Handle case when one string ends
     }

     int main() {
         char str1[] = "Hello";
         char str2[] = "Hello";
         int result = stringCompare(str1, str2);

         if (result == 0) {
             printf("Strings are equal.\n");
         } else if (result < 0) {
             printf("String 1 is less than String 2.\n");
         } else {
             printf("String 1 is greater than String 2.\n");
         }

         return 0;
     }
     ```
   -

 **Explanation**: The `stringCompare` function compares two strings character by character using pointers and returns the difference, indicating their relative order.

### 9. File Handling

**a. Create a program to write a list of integers to a file and read them back.**
   - **Objective**: Learn basic file I/O operations.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         FILE *file = fopen("numbers.txt", "w"); // Open file for writing
         if (file == NULL) {
             printf("Error opening file for writing.\n");
             return 1;
         }

         for (int i = 1; i <= 10; i++) {
             fprintf(file, "%d\n", i); // Write integers to file
         }

         fclose(file); // Close the file

         // Reading back the integers
         file = fopen("numbers.txt", "r"); // Open file for reading
         if (file == NULL) {
             printf("Error opening file for reading.\n");
             return 1;
         }

         printf("Numbers read from file:\n");
         int num;
         while (fscanf(file, "%d", &num) != EOF) {
             printf("%d ", num); // Read and print integers
         }
         printf("\n");

         fclose(file); // Close the file
         return 0;
     }
     ```
   - **Explanation**: The program opens a file for writing, writes a series of integers to it, then reopens the file to read the integers back.

**b. Implement a program to append data to a file and display its contents.**
   - **Objective**: Learn to append data to files and read them.
   - **Code**:
     ```c
     #include <stdio.h>

     int main() {
         FILE *file = fopen("data.txt", "a"); // Open file for appending
         if (file == NULL) {
             printf("Error opening file for appending.\n");
             return 1;
         }

         fprintf(file, "New data line.\n"); // Append data to file
         fclose(file); // Close the file

         // Displaying the contents of the file
         file = fopen("data.txt", "r"); // Open file for reading
         if (file == NULL) {
             printf("Error opening file for reading.\n");
             return 1;
         }

         printf("Contents of the file:\n");
         char line[100];
         while (fgets(line, sizeof(line), file) != NULL) {
             printf("%s", line); // Read and print lines
         }

         fclose(file); // Close the file
         return 0;
     }
     ```
   - **Explanation**: This program appends a new line of text to an existing file and then reads and displays the entire contents of the file.

### 10. Multithreading

**a. Write a program to create two threads that print numbers concurrently.**
   - **Objective**: Understand how to create and manage threads.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <pthread.h>
     #include <unistd.h>

     void *printNumbers(void *arg) {
         int *num = (int *)arg;
         for (int i = 0; i < 5; i++) {
             printf("%d ", *num); // Print the number
             sleep(1); // Sleep for a second
         }
         return NULL;
     }

     int main() {
         pthread_t thread1, thread2;
         int num1 = 1, num2 = 2;

         pthread_create(&thread1, NULL, printNumbers, &num1); // Create first thread
         pthread_create(&thread2, NULL, printNumbers, &num2); // Create second thread

         pthread_join(thread1, NULL); // Wait for first thread to finish
         pthread_join(thread2, NULL); // Wait for second thread to finish

         printf("\n");
         return 0;
     }
     ```
   - **Explanation**: The program creates two threads, each printing a number concurrently. The `printNumbers` function prints the assigned number five times with a one-second interval.

**b. Implement a program that uses mutexes to control access to a shared resource.**
   - **Objective**: Learn to use mutexes for thread synchronization.
   - **Code**:
     ```c
     #include <stdio.h>
     #include <pthread.h>

     int sharedCounter = 0; // Shared resource
     pthread_mutex_t mutex; // Mutex for synchronization

     void *incrementCounter(void *arg) {
         for (int i = 0; i < 100000; i++) {
             pthread_mutex_lock(&mutex); // Lock the mutex
             sharedCounter++; // Increment the shared counter
             pthread_mutex_unlock(&mutex); // Unlock the mutex
         }
         return NULL;
     }

     int main() {
         pthread_t thread1, thread2;
         pthread_mutex_init(&mutex, NULL); // Initialize the mutex

         pthread_create(&thread1, NULL, incrementCounter, NULL); // Create first thread
         pthread_create(&thread2, NULL, incrementCounter, NULL); // Create second thread

         pthread_join(thread1, NULL); // Wait for first thread to finish
         pthread_join(thread2, NULL); // Wait for second thread to finish

         printf("Final value of sharedCounter: %d\n", sharedCounter);

         pthread_mutex_destroy(&mutex); // Destroy the mutex
         return 0;
     }
     ```
   - **Explanation**: This program demonstrates the use of a mutex to protect access to a shared counter. Two threads increment the counter, but the mutex ensures that only one thread can modify it at a time, preventing race conditions.

These examples provide a comprehensive overview of essential C programming concepts, including pointers, dynamic memory allocation, structures, file handling, and multithreading. Each example illustrates practical usage and helps solidify your understanding of these fundamental topics.
