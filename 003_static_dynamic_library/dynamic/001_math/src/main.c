#include <stdio.h>
#include "mathlib.h"

int main() {
    int a = 10, b = 5;

    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    printf("Sub: %d - %d = %d\n", a, b, sub(a, b));
    printf("Mul: %d * %d = %d\n", a, b, mul(a, b));

    return 0;
}

