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

