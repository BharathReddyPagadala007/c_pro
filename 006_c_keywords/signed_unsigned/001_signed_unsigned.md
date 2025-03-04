---

### Example 1: Overflow and Wraparound
```c
#include <stdio.h>

int main() {
    unsigned int u = 0;
    signed int s = 0;

    u = u - 1; // Underflow in unsigned int
    s = s - 1; // Decrease in signed int

    printf("Unsigned int underflow: %u\n", u);
    printf("Signed int after decrement: %d\n", s);

    return 0;
}
```

- **Key Concept:** Observe how unsigned integers wrap around when they go below zero, while signed integers decrease normally.

---

### Example 2: Signed vs Unsigned Comparison
```c
#include <stdio.h>

int main() {
    unsigned int u = 1;
    signed int s = -1;

    if (s > u) {
        printf("Signed int is greater than unsigned int\n");
    } else {
        printf("Unsigned int is greater than or equal to signed int\n");
    }

    return 0;
}
```

- **Key Concept:** Understand how the signed integer is converted to unsigned during comparison, leading to unexpected results.

---

### Example 3: Bitwise Representation
```c
#include <stdio.h>

void printBits(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int u = 4294967295; // Max value for 32-bit unsigned
    signed int s = -1;          // Signed equivalent of all bits set to 1

    printf("Unsigned int (4294967295) in binary: ");
    printBits(u);

    printf("Signed int (-1) in binary: ");
    printBits((unsigned int)s); // Interpret signed as unsigned to print

    return 0;
}
```

- **Key Concept:** Observe how the same bit pattern can represent different values for signed and unsigned integers.

---

### Example 4: Mixing Signed and Unsigned Arithmetic
```c
#include <stdio.h>

int main() {
    unsigned int u = 10;
    signed int s = -5;

    printf("Unsigned + Signed: %u\n", u + s);
    printf("Signed + Unsigned (explicit cast): %d\n", s + (signed int)u);

    return 0;
}
```

- **Key Concept:** See how implicit casting in mixed arithmetic operations can lead to unexpected results.

---

### Example 5: Boundary Conditions
```c
#include <stdio.h>
#include <limits.h>

int main() {
    printf("Maximum signed int: %d\n", INT_MAX);
    printf("Minimum signed int: %d\n", INT_MIN);
    printf("Maximum unsigned int: %u\n", UINT_MAX);

    signed int s = INT_MAX;
    unsigned int u = UINT_MAX;

    printf("Signed int after overflow: %d\n", s + 1);
    printf("Unsigned int after overflow: %u\n", u + 1);

    return 0;
}
```

- **Key Concept:** Learn about the limits of `int` types and how they behave when overflow occurs.

---

#### Practice Ideas:
1. Modify the programs to handle inputs dynamically (using `scanf`).
2. Add error-checking to observe undefined behavior (e.g., dividing by zero).
3. Experiment with different data types like `short`, `long`, and `long long` with signed and unsigned variations.
-----

---

### Example 6: Implicit Type Promotion
```c
#include <stdio.h>

int main() {
    unsigned char uc = 200;
    signed char sc = -50;

    // Adding unsigned and signed
    printf("Unsigned char + Signed char: %d\n", uc + sc);

    // Type promotion happens here
    printf("Unsigned char in promotion: %d\n", (int)uc);
    printf("Signed char in promotion: %d\n", (int)sc);

    return 0;
}
```

- **Key Concept:** Small data types like `char` are promoted to `int` during arithmetic operations. This can change the behavior of signed and unsigned numbers.

---

### Example 7: Signed and Unsigned Loops
```c
#include <stdio.h>

int main() {
    unsigned int i;
    printf("Unsigned Loop:\n");
    for (i = 5; i >= 0; i--) { // Watch for an infinite loop
        printf("%u ", i);
    }

    printf("\nSigned Loop:\n");
    for (int j = 5; j >= 0; j--) {
        printf("%d ", j);
    }

    return 0;
}
```

- **Key Concept:** Unsigned integers do not become negative, causing wraparound behavior. This can lead to infinite loops if not handled correctly.

---

### Example 8: Negative Values in Unsigned Contexts
```c
#include <stdio.h>

int main() {
    unsigned int u = 5;
    signed int s = -10;

    printf("Unsigned after adding signed negative: %u\n", u + s);
    printf("Unsigned value of signed negative: %u\n", (unsigned int)s);

    return 0;
}
```

- **Key Concept:** Casting negative signed values to unsigned changes their interpretation, often resulting in very large numbers due to wraparound.

---

### Example 9: Real-World Error in Signed/Unsigned Mix
```c
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    unsigned int i;

    // Wrong comparison, mix of signed and unsigned
    for (i = 0; i <= sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nCorrected Comparison:\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

- **Key Concept:** Mixing signed and unsigned in conditions may lead to logical errors like infinite loops or incorrect index calculations.

---

### Example 10: Debugging Signed/Unsigned Pitfalls
```c
#include <stdio.h>

int main() {
    unsigned int large = 3000000000; // Greater than INT_MAX
    signed int small = -100;

    printf("Signed: %d, Unsigned: %u\n", small, large);

    if (small < large) {
        printf("Signed is smaller than Unsigned (unexpected?)\n");
    } else {
        printf("Unsigned comparison behavior wins here\n");
    }

    return 0;
}
```

- **Key Concept:** Observe how comparisons between signed and unsigned values can produce unintuitive results, especially when unsigned values exceed `INT_MAX`.

---

### Example 11: Detecting Overflow Conditions
```c
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int u = UINT_MAX; // Maximum value
    signed int s = INT_MAX;

    printf("Before Overflow - Unsigned: %u, Signed: %d\n", u, s);

    // Overflow
    u += 1;
    s += 1;

    printf("After Overflow - Unsigned: %u, Signed: %d\n", u, s);

    return 0;
}
```

- **Key Concept:** Understand the behavior of signed and unsigned overflow and how to detect it programmatically.

---

### Example 12: Right Shift Behavior
```c
#include <stdio.h>

int main() {
    unsigned int u = 0xFFFFFFFF; // All bits set
    signed int s = -1;

    printf("Unsigned right shift: %u\n", u >> 1);
    printf("Signed right shift: %d\n", s >> 1);

    return 0;
}
```

- **Key Concept:** Right shift behaves differently for signed and unsigned integers; for signed integers, the result depends on the compiler and whether arithmetic or logical shifts are used.

---

### Example 13: Converting Between Signed and Unsigned Safely
```c
#include <stdio.h>

int main() {
    unsigned int u = 100;
    signed int s = -50;

    // Conversion with boundary check
    if (s < 0) {
        printf("Signed to Unsigned safely: Undefined (negative value)\n");
    } else {
        unsigned int safe_u = (unsigned int)s;
        printf("Signed to Unsigned: %u\n", safe_u);
    }

    return 0;
}
```

- **Key Concept:** Always validate ranges when converting between signed and unsigned types to prevent unexpected behavior.

---

#### Advanced Practice Ideas:
1. **Simulate Memory Corruption:** Experiment with `memcpy` using signed and unsigned integers to simulate how bits are interpreted differently.
2. **Dynamic Arrays:** Write code to handle arrays with both signed and unsigned indices and debug logical pitfalls.
3. **Bit Manipulation Projects:** Combine signed and unsigned integers in bitwise operations to explore edge cases.

---
Bit manipulation provides an excellent way to dive deeper into how signed and unsigned integers work at the binary level. These examples highlight how the interpretation of bits changes depending on whether the integer is signed or unsigned.

---

### Example 1: Understanding Signed and Unsigned Representations
```c
#include <stdio.h>

void printBits(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int u = 5;
    signed int s = -5;

    printf("Unsigned int (5) in binary: ");
    printBits(u);

    printf("Signed int (-5) in binary: ");
    printBits((unsigned int)s); // Interpret signed as unsigned

    return 0;
}
```

- **Key Concept:** Observe how signed integers use **two's complement** representation, where negative numbers have the most significant bit (MSB) set.

---

### Example 2: Sign Extension in Bit Shifts
```c
#include <stdio.h>

int main() {
    unsigned int u = 0b1001; // 9 in binary
    signed int s = -9;

    printf("Unsigned left shift (u << 1): %u\n", u << 1);
    printf("Signed left shift (s << 1): %d\n", s << 1);

    printf("Unsigned right shift (u >> 1): %u\n", u >> 1);
    printf("Signed right shift (s >> 1): %d\n", s >> 1);

    return 0;
}
```

- **Key Concept:** Left shifts work the same for signed and unsigned integers, but right shifts differ. For signed integers, arithmetic right shifts propagate the sign bit, while unsigned shifts fill with zeros.

---

### Example 3: Checking the MSB
```c
#include <stdio.h>

int main() {
    unsigned int u = 2147483648; // MSB set
    signed int s = -1;           // All bits set in signed

    printf("Unsigned int MSB check: %s\n", (u & 0x80000000) ? "Set" : "Not set");
    printf("Signed int MSB check: %s\n", (s & 0x80000000) ? "Set" : "Not set");

    return 0;
}
```

- **Key Concept:** The MSB in a signed integer represents the sign (positive or negative), whereas in an unsigned integer, it is simply a large value bit.

---

### Example 4: Reversing Bits
```c
#include <stdio.h>

unsigned int reverseBits(unsigned int num) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result |= ((num >> i) & 1) << (31 - i);
    }
    return result;
}

int main() {
    unsigned int u = 5; // Binary: 00000000000000000000000000000101
    signed int s = -5;  // Binary: 11111111111111111111111111111011

    printf("Unsigned (5) reversed: %u\n", reverseBits(u));
    printf("Signed (-5) reversed (interpreted as unsigned): %u\n", reverseBits((unsigned int)s));

    return 0;
}
```

- **Key Concept:** Observe how reversing bits in signed and unsigned integers leads to drastically different results due to their binary representation.

---

### Example 5: Counting Set Bits
```c
#include <stdio.h>

int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    unsigned int u = 7; // Binary: 00000000000000000000000000000111
    signed int s = -7;  // Binary: 11111111111111111111111111111001

    printf("Unsigned (7) set bits: %d\n", countSetBits(u));
    printf("Signed (-7) set bits (interpreted as unsigned): %d\n", countSetBits((unsigned int)s));

    return 0;
}
```

- **Key Concept:** Count the number of `1`s in signed and unsigned integers to see how two's complement affects bit patterns.

---

### Example 6: Flipping Bits
```c
#include <stdio.h>

int main() {
    unsigned int u = 5; // Binary: 00000000000000000000000000000101
    signed int s = -5;  // Binary: 11111111111111111111111111111011

    printf("Unsigned (5) flipped: %u\n", ~u);
    printf("Signed (-5) flipped: %d\n", ~s);

    return 0;
}
```

- **Key Concept:** The `~` operator flips all bits, but interpreting the result depends on whether the integer is signed or unsigned.

---

### Example 7: Detecting Overflow in Signed Addition
```c
#include <stdio.h>
#include <limits.h>

int main() {
    signed int a = INT_MAX;
    signed int b = 1;

    signed int result = a + b;
    if ((a > 0 && b > 0 && result < 0) || (a < 0 && b < 0 && result > 0)) {
        printf("Overflow detected in signed addition\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
```

- **Key Concept:** Use bitwise techniques to detect signed overflow during addition.

---

### Example 8: Detecting Power of Two
```c
#include <stdio.h>

int isPowerOfTwo(unsigned int num) {
    return (num & (num - 1)) == 0 && num != 0;
}

int main() {
    unsigned int u = 8;
    signed int s = -8;

    printf("Is unsigned (8) a power of two? %s\n", isPowerOfTwo(u) ? "Yes" : "No");
    printf("Is signed (-8) a power of two? %s\n", isPowerOfTwo((unsigned int)s) ? "Yes" : "No");

    return 0;
}
```

- **Key Concept:** Detect whether a number is a power of two. Signed integers may require conversion to unsigned for accurate bitwise operations.

---

### Example 9: Arithmetic vs Logical Shift
```c
#include <stdio.h>

int main() {
    unsigned int u = 0xF0000000; // Binary: 11110000...
    signed int s = (int)u;

    printf("Unsigned right shift: %u\n", u >> 4);
    printf("Signed right shift: %d\n", s >> 4);

    return 0;
}
```

- **Key Concept:** Unsigned shifts always fill with zeros, while signed shifts depend on the compiler (logical vs arithmetic).

---

### Advanced Practice:
1. **Parity Check:** Write a function to determine if a number has even or odd parity using bitwise operations.
2. **Binary to Decimal Conversion:** Use bit manipulation to convert a binary number (stored as an integer) to its decimal equivalent.
3. **Bitwise AND/OR Table:** Create a truth table for combinations of signed and unsigned integers.

