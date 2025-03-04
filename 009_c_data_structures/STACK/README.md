
### 1. **Implement a stack using an array**
   - **Problem Description:** 
     - Create a program to implement a stack using a fixed-size array in C. 
     - The stack should have the following functionalities:
       - `push(int value)`: Add an element to the top of the stack.
       - `pop()`: Remove and return the element from the top of the stack.
       - `peek()`: Return the top element of the stack without removing it.
       - `isEmpty()`: Check if the stack is empty.
       - `isFull()`: Check if the stack is full (since the stack is implemented using a fixed-size array).
   - **Constraints:** 
     - Handle edge cases like stack overflow (when trying to `push` onto a full stack) and stack underflow (when trying to `pop` from an empty stack).

### 2. **Implement a stack using a linked list**
   - **Problem Description:** 
     - Implement a stack in C using a linked list for dynamic memory allocation. This approach allows the stack to grow as needed, without a fixed size.
     - The stack should support the following operations:
       - `push(int value)`: Insert an element at the top of the stack.
       - `pop()`: Remove and return the element from the top of the stack.
       - `peek()`: Return the top element without removing it.
       - `isEmpty()`: Check if the stack is empty.
   - **Details:** 
     - Use a linked list node structure with a `data` field for storing the value and a `next` pointer for the next node.
     - Consider edge cases such as popping from an empty stack.

### 3. **Reverse a string using a stack**
   - **Problem Description:** 
     - Given a string, use a stack to reverse the order of its characters.
     - For example, if the input string is `"hello"`, the reversed string should be `"olleh"`.
   - **Approach:** 
     - Push each character of the string onto the stack.
     - Pop each character from the stack to form the reversed string.
   - **Constraints:** 
     - The program should handle strings with different lengths, including empty strings.

### 4. **Check if parentheses in an expression are balanced**
   - **Problem Description:** 
     - Given an expression containing different types of parentheses (e.g., `()`, `{}`, `[]`), use a stack to check if the parentheses are balanced.
     - An expression is considered balanced if every opening parenthesis has a corresponding closing parenthesis in the correct order.
     - For example, `({[]})` is balanced, but `({[})` is not.
   - **Approach:** 
     - Traverse the expression character by character.
     - Push opening parentheses onto the stack.
     - For each closing parenthesis, check if the stack is not empty and if the top of the stack is the matching opening parenthesis. If not, the expression is unbalanced.
     - In the end, the stack should be empty for the expression to be considered balanced.
   - **Constraints:** 
     - Handle cases where the expression has only opening or closing parentheses.

### 5. **Find the span of stock prices for each day using a stack**
   - **Problem Description:** 
     - Given an array of stock prices where each element represents the price of a stock on a given day, find the span of stock prices for each day.
     - The span of a stock price on a particular day is defined as the number of consecutive days before that day (including the current day) where the price of the stock was less than or equal to the price on the current day.
     - For example, for stock prices `[100, 80, 60, 70, 60, 75, 85]`, the spans would be `[1, 1, 1, 2, 1, 4, 6]`.
   - **Approach:** 
     - Use a stack to keep track of indices of the stock prices.
     - For each day, check how many previous consecutive days had a lower or equal price.
     - This can be efficiently calculated using a stack to maintain the indices of the stock prices that have not yet been spanned.
   - **Constraints:** 
     - The program should handle cases where prices do not increase or decrease monotonically.

