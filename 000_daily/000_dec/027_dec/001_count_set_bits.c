//===========================================
//https://leetcode.com/problems/counting-bits/description/
//==========================================
#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* preturnSize) {

    int* ans = (int*)malloc((n + 1) * (sizeof(int)));
    *preturnSize = n + 1;

    ans[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;

        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

int main(){

	int n;
	n=15;


    int returnSize = 0;
    int* result = countBits(n, &returnSize);

    if (!result) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Number of set bits from 0 to %d:\n", n);
    for (int i = 0; i < returnSize; i++) {
        //printf("num=%d -> bits=%d\n", i, result[i]);
        printf("%d  ",  result[i]);
    }
    printf("\n");

    free(result);

	

return 0;
}
