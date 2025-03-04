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

