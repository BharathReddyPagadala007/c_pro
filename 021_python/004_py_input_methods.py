"""
1. Normal Method
This is the simplest and most commonly used method using input() for taking input and print() for displaying output.

input() always reads input as a string, so we need to typecast it (e.g., to int).
For arrays/lists, we can use split() and map() to convert them into integers.
It works fine for small inputs, but it is slow for large inputs, which is why competitive programmers prefer other methods.
Example: This code takes n as the number of inputs, then reads n integers, sums them up and prints the result.
"""


n = int(input())
arr = [int(x) for x in input().split()]
summ =0

for x in arr:
    summ+=x
print(summ)
