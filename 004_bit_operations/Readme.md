
### 1. **Check if a Number is Even or Odd**
   - **Problem**: Write a function that checks whether a given integer is even or odd using bit manipulation.
   - **Hint**: Use the bitwise AND operator (`&`).

### 2. **Count the Number of Set Bits**
   - **Problem**: Write a function to count the number of `1` bits (set bits) in the binary representation of an integer.
   - **Hint**: Use the bitwise AND operator with `1` and shift the bits.

### 3. **Find the Only Non-Repeating Element**
   - **Problem**: Given an array where every element appears twice except for one element, find the single non-repeating element using bit manipulation.
   - **Hint**: Use the XOR operator (`^`) to solve this in linear time.

### 4. **Swap Two Numbers Without Using a Temporary Variable**
   - **Problem**: Write a function to swap two integers using bit manipulation, without using a temporary variable.
   - **Hint**: Use the XOR operator.

### 5. **Check if a Number is a Power of 2**
   - **Problem**: Write a function that checks if a given integer is a power of 2.
   - **Hint**: A number is a power of 2 if it has exactly one set bit.

### 6. **Set a Specific Bit**
   - **Problem**: Write a function to set the `n`-th bit of an integer to `1`.
   - **Hint**: Use the bitwise OR operator with a shifted bitmask.

### 7. **Clear a Specific Bit**
   - **Problem**: Write a function to clear the `n`-th bit of an integer (set it to `0`).
   - **Hint**: Use the bitwise AND operator with a negated shifted bitmask.

### 8. **Toggle a Specific Bit**
   - **Problem**: Write a function to toggle the `n`-th bit of an integer.
   - **Hint**: Use the bitwise XOR operator with a shifted bitmask.

### 9. **Reverse the Bits of a Number**
   - **Problem**: Write a function to reverse the bits of an integer.
   - **Hint**: Use bitwise operations to reverse each bit position.

### 10. **Find the Position of the Most Significant Bit (MSB)**
   - **Problem**: Write a function to find the position of the most significant bit set in a given integer.
   - **Hint**: You can shift the number to the right until it becomes zero, counting the number of shifts.

### 11. **Find the Next Power of 2 for a Given Number**
   - **Problem**: Given a number `n`, find the smallest power of 2 that is greater than or equal to `n`.
   - **Hint**: Use bit shifting to accomplish this.

### 12. **Check if Two Numbers have Opposite Signs**
   - **Problem**: Write a function to check if two integers have opposite signs.
   - **Hint**: Use the XOR operator.

### 13. **Isolate the Rightmost Set Bit**
   - **Problem**: Write a function that isolates the rightmost set bit of an integer.
   - **Hint**: Use the expression `x & -x`.

### 14. **Turn Off the Rightmost Set Bit**
   - **Problem**: Write a function to turn off the rightmost set bit of an integer.
   - **Hint**: Use the expression `x & (x - 1)`.

### 15. **Check if a Number has Alternating Bits**
   - **Problem**: Given a number, check if its binary representation has alternating `1`s and `0`s (like `101010`).
   - **Hint**: Use bitwise shifting and XOR.

### 16. **Add Two Numbers Without Using Arithmetic Operators**
   - **Problem**: Write a function to add two integers without using the `+` or `-` operators.
   - **Hint**: Use bitwise XOR for addition and bitwise AND and shifting for carry.

### 17. **Find the Number of Bits to Flip to Convert `A` to `B`**
   - **Problem**: Given two integers `A` and `B`, find the number of bits you need to flip in `A` to get `B`.
   - **Hint**: Use XOR to find differing bits.

### 18. **Determine if All Bits are Set in an Integer**
   - **Problem**: Write a function to check if all bits of a given integer are set to `1`.
   - **Hint**: Compare the number to `(1 << n) - 1`, where `n` is the number of bits in the integer.

### 19. **Extract the Lowest `k` Bits of an Integer**
   - **Problem**: Given an integer and a number `k`, extract the lowest `k` bits of the integer.
   - **Hint**: Use a bitmask `(1 << k) - 1`.

### 20. **Find the Parity of a Number**
   - **Problem**: Determine whether the number of set bits in an integer is odd or even (parity check).
   - **Hint**: Use XOR to find the parity efficiently.

### 21. **Rotate Bits Left or Right**
   - **Problem**: Write functions to perform bitwise rotation of an integer's bits to the left or right by `n` positions.
   - **Hint**: Combine shifting and bitwise OR for wrapping around.

### 22. **Generate All Subsets of a Set Using Bitmasking**
   - **Problem**: Given an array, generate all its subsets using bit manipulation.
   - **Hint**: Use numbers from `0` to `2^n - 1` as bitmasks.

### 23. **Find the Most Significant Bit (MSB) Set in an Integer**
   - **Problem**: Write a function to find the most significant bit set in an integer.
   - **Hint**: You can keep shifting the number right until it becomes zero.

### 24. **Check if a Number is a Palindrome in Binary**
   - **Problem**: Determine if the binary representation of a number is a palindrome.
   - **Hint**: Compare the original number with its reversed bits.

### 25. **Multiply a Number by 7 Using Bit Manipulation**
   - **Problem**: Write a function to multiply a given integer by 7 without using the multiplication operator.
   - **Hint**: Use bit shifting and addition.

### 26. **Divide a Number by 2 Without Using Division**
   - **Problem**: Write a function to divide an integer by 2 without using the division operator.
   - **Hint**: Use bit shifting.

### 27. **Find the Index of the Least Significant Set Bit**
   - **Problem**: Given a number, find the index (position) of the least significant set bit.
   - **Hint**: Use the expression `x & -x` and `__builtin_ctz` (GCC extension) to count trailing zeros.

### 28. **Reverse Bits Within a Given Range**
   - **Problem**: Reverse the bits of an integer within a specified range `[i, j]`.
   - **Hint**: Extract, reverse, and place them back using bit manipulation.

### 29. **Convert a Binary String to an Integer**
   - **Problem**: Write a function that converts a given binary string to its integer representation using bit manipulation.
   - **Hint**: Iterate over the string, shifting and adding as you go.

### 30. **Check if Two Numbers Differ by Exactly One Bit**
   - **Problem**: Given two integers, check if they differ by exactly one bit.
   - **Hint**: Use XOR and check if the result is a power of 2.

