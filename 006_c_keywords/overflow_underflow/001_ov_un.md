**Underflow** and **overflow** occur when a calculation exceeds the range that a data type can represent in a programming language. Let’s break it down with examples in **C**:

---

### **1. Overflow**
Occurs when the result of a calculation is **larger than the maximum value** a data type can hold, causing it to wrap around (in unsigned types) or behave unpredictably (in signed types).

#### **Example (Unsigned Integer Overflow):**
```c
#include <stdio.h>

int main() {
    unsigned char max = 255; // Maximum value of unsigned char
    unsigned char result = max + 1; // Exceeds max range

    printf("Unsigned Overflow: %u\n", result);
    return 0;
}
```

#### **Explanation:**
- `unsigned char` can hold values between `0` and `255`.
- Adding `1` to `255` causes it to "wrap around" to `0` due to modulo arithmetic.

---

#### **Example (Signed Integer Overflow):**
```c
#include <stdio.h>

int main() {
    signed char max = 127; // Maximum value of signed char
    signed char result = max + 1; // Exceeds max range

    printf("Signed Overflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- `signed char` can hold values between `-128` and `127`.
- Adding `1` to `127` may produce unexpected behavior because overflow in signed integers is undefined in C.

---

### **2. Underflow**
Occurs when the result of a calculation is **smaller than the minimum value** a data type can hold, causing it to wrap around (unsigned types) or behave unpredictably (signed types).

#### **Example (Unsigned Integer Underflow):**
```c
#include <stdio.h>

int main() {
    unsigned char min = 0; // Minimum value of unsigned char
    unsigned char result = min - 1; // Below min range

    printf("Unsigned Underflow: %u\n", result);
    return 0;
}
```

#### **Explanation:**
- `unsigned char` can hold values between `0` and `255`.
- Subtracting `1` from `0` causes it to wrap around to `255`.

---

#### **Example (Signed Integer Underflow):**
```c
#include <stdio.h>

int main() {
    signed char min = -128; // Minimum value of signed char
    signed char result = min - 1; // Below min range

    printf("Signed Underflow: %d\n", result);
    return 0;
}
```

#### **Explanation:**
- `signed char` can hold values between `-128` and `127`.
- Subtracting `1` from `-128` may produce unexpected results because signed integer underflow is undefined in C.

---

### **Floating-Point Overflow and Underflow**
- **Overflow:** When a floating-point number exceeds the largest representable number, it becomes `+Infinity` or `-Infinity`.
- **Underflow:** When a floating-point number is too small to be represented, it becomes `0`.

#### **Example (Floating-Point):**
```c
#include <stdio.h>
#include <float.h>

int main() {
    float large = FLT_MAX; // Maximum float value
    float small = FLT_MIN; // Minimum positive float value

    printf("Float Overflow: %e\n", large * 10.0); // Results in infinity
    printf("Float Underflow: %e\n", small / 10.0); // May result in zero

    return 0;
}
```

---

### **Key Points**
1. Overflow and underflow can occur in **integer** and **floating-point** operations.
2. **Unsigned types** wrap around using modulo arithmetic.
3. **Signed types** overflow/underflow behavior is undefined (implementation-specific).
4. Prevent overflow/underflow using checks or larger data types (e.g., `long` or `long long`).
