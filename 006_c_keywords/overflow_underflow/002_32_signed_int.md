For a **signed 32-bit integer**, the range is:

\[
\text{Range: } -2^{31} \, \text{to} \, 2^{31} - 1 \, \text{(or)} \, -2,147,483,648 \, \text{to} \, 2,147,483,647
\]

Here are examples of **overflow** and **underflow** in C using a signed 32-bit integer:

---

### **1. Signed Integer Overflow**
Overflow occurs when the result exceeds `2,147,483,647`.

#### **Example:**
```c
#include <stdio.h>

int main() {
    int max = 2147483647; // Maximum value of signed 32-bit integer
    int result = max + 1; // Causes overflow

    printf("Signed Overflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- Adding `1` to `2147483647` causes the value to wrap around to `-2147483648` due to how binary arithmetic works in two's complement representation.
  
---

### **2. Signed Integer Underflow**
Underflow occurs when the result goes below `-2,147,483,648`.

#### **Example:**
```c
#include <stdio.h>

int main() {
    int min = -2147483648; // Minimum value of signed 32-bit integer
    int result = min - 1; // Causes underflow

    printf("Signed Underflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- Subtracting `1` from `-2147483648` causes the value to wrap around to `2147483647` due to two's complement arithmetic.

---

### **3. Multiplication Overflow**
Overflow can also occur during multiplication when the result exceeds the maximum value.

#### **Example:**
```c
#include <stdio.h>

int main() {
    int a = 1 << 30; // 2^30 = 1073741824
    int b = 4;       // Multiplying with 4 causes overflow
    int result = a * b;

    printf("Multiplication Overflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- The product of `1073741824 * 4` exceeds `2147483647` and wraps around to a negative value.

---

### **4. Multiplication Underflow**
Underflow can occur when multiplying negative numbers and exceeding the negative limit.

#### **Example:**
```c
#include <stdio.h>

int main() {
    int a = -1 << 30; // -2^30 = -1073741824
    int b = 2;        // Multiplying with 2 causes underflow
    int result = a * b;

    printf("Multiplication Underflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- The product of `-1073741824 * 2` wraps around and exceeds the negative range.

---

### **5. Practical Example of Overflow in a Loop**
Overflow often happens unintentionally in loops or calculations:

#### **Example:**
```c
#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 0; i < 100000; i++) {
        sum += 100000; // Incrementally increasing value
    }
    printf("Result after overflow: %d\n", sum);
    return 0;
}
```

#### **Explanation:**
- The `sum` variable eventually exceeds the maximum range (`2,147,483,647`) and wraps around to a negative value.

---

### **Behavior in Signed Overflow/Underflow**
In C:
- **Signed integer overflow and underflow are undefined behavior.** 
- The results may vary depending on the compiler and platform.

To handle this:
1. Use **larger data types** like `long long` if you expect large calculations.
2. Implement **range checks** before performing operations.
