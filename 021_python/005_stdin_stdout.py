from sys import stdin,stdout
def main():
    n = int(stdin.readline())
    arr = [int(x) for x in stdin.readline().split()]
    summation = sum(arr)
    stdout.write(str(summation))

if __name__ == "__main__":
    main()






"""
2. Faster Method Using stdin and stdout
Python’s sys.stdin and sys.stdout are much faster than input() and print().

stdin.readline() reads input directly from the input buffer.
stdout.write() outputs results faster because it avoids the formatting overhead of print().
This method is widely used in competitive programming for speed optimization.

Example: This program reads input using stdin.readline(), computes the sum of numbers and prints it using stdout.write().

"""

"""
Explanation:

stdin.readline() reads input as raw text much faster.
stdout.write() avoids extra formatting overhead of print().
Timing comparison (100k lines each):

print(): 6.040s
Writing to file: 0.122s
stdout.write(): 0.121s
Clearly, stdin + stdout is much faster.
"""
