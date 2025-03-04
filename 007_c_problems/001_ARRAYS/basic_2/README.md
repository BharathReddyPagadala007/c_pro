
19. **Find All Prime Numbers in an Array**
    - **Problem**: Identify and list all the prime numbers in a given array.
    - **Example**: For `[10, 11, 15, 17, 18]`, the prime numbers are `11` and `17`.
    - **Hints**: Implement a function to check if a number is prime, then filter the array using this function.

20. **Find the Majority Element**
    - **Problem**: Find the element that appears more than half the time in an array, if such an element exists.
    - **Example**: In `[3, 3, 4, 2, 3]`, the majority element is `3`.
    - **Hints**: Use a frequency count or the Boyer-Moore Voting Algorithm.

21. **Find the Median of an Array**
    - **Problem**: Calculate the median value of a sorted array.
    - **Example**: For `[1, 3, 4, 8, 9]`, the median is `4`. For `[1, 2, 3, 4]`, it’s the average of `2` and `3` (`2.5`).
    - **Hints**: Sort the array if it’s not already sorted, then find the middle element(s).

22. **Rearrange Positive and Negative Numbers Alternately**
    - **Problem**: Rearrange an array so that positive and negative numbers alternate, preserving the order within each group.
    - **Example**: For `[3, -2, 5, -7, 8]`, one possible rearrangement is `[3, -2, 5, -7, 8]`.
    - **Hints**: Partition the array into positives and negatives, then merge them back alternately.

23. **Move All Zeroes to the End**
    - **Problem**: Given an array, move all zeroes to the end while maintaining the relative order of non-zero elements.
    - **Example**: `[0, 1, 0, 3, 12]` becomes `[1, 3, 12, 0, 0]`.
    - **Hints**: Traverse the array and shift non-zero elements forward.

24. **Find the Kth Smallest/Largest Element**
    - **Problem**: Find the Kth smallest or largest element in an unsorted array.
    - **Example**: The 2nd largest element in `[5, 3, 1, 8, 9]` is `8`.
    - **Hints**: Use sorting or a selection algorithm like QuickSelect.

25. **Array Rotation Using Reversal Algorithm**
    - **Problem**: Rotate an array to the left by `d` positions using the reversal algorithm.
    - **Example**: Rotating `[1, 2, 3, 4, 5]` by `2` positions results in `[3, 4, 5, 1, 2]`.
    - **Hints**: Reverse segments of the array and then the entire array.

26. **Check if an Array is a Palindrome**
    - **Problem**: Determine if an array reads the same forward and backward.
    - **Example**: `[1, 2, 3, 2, 1]` is a palindrome.
    - **Hints**: Compare elements from the start and end, moving toward the center.

27. **Split an Array into Two Equal Sums**
    - **Problem**: Check if an array can be split into two subarrays with equal sums.
    - **Example**: `[1, 2, 3, 4, 6]` can be split into `[1, 2, 3]` and `[4, 6]`.
    - **Hints**: Use a running sum to check for possible split points.

28. **Find All Subarrays with a Given Sum**
    - **Problem**: Identify all subarrays within an array that sum up to a specific target.
    - **Example**: For `[1, 2, 3, 4]` with a sum of `5`, subarrays `[2, 3]` and `[1, 4]` qualify.
    - **Hints**: Use nested loops or a sliding window approach for optimization.

29. **Replace Each Element with the Greatest Element to its Right**
    - **Problem**: Update each element in an array to the greatest element among the elements to its right.
    - **Example**: For `[16, 17, 4, 3, 5, 2]`, the result is `[17, 5, 5, 5, 2, -1]`.
    - **Hints**: Traverse the array from the right while keeping track of the maximum value.

30. **Find the Longest Increasing Subsequence**
    - **Problem**: Determine the longest subsequence in which the elements are in strictly increasing order.
    - **Example**: In `[10, 22, 9, 33, 21, 50, 41, 60]`, the longest increasing subsequence is `[10, 22, 33, 50, 60]`.
    - **Hints**: Use dynamic programming or a binary search-based approach.

31. **Rotate Matrix (2D Array) by 90 Degrees**
    - **Problem**: Rotate a given square matrix by 90 degrees clockwise.
    - **Example**: For a 2x2 matrix `[[1, 2], [3, 4]]`, rotating 90 degrees results in `[[3, 1], [4, 2]]`.
    - **Hints**: Transpose the matrix and then reverse each row.

32. **Find the Minimum Distance Between Two Elements**
    - **Problem**: Find the minimum distance between two specified elements in an array.
    - **Example**: In `[3, 5, 4, 2, 6, 3, 5, 2, 5]`, the minimum distance between `3` and `5` is `2`.
    - **Hints**: Track the positions of the two elements and update the minimum distance.

33. **Check for a Triplet Sum**
    - **Problem**: Determine if there exists a triplet (three numbers) in the array that sums up to a specific value.
    - **Example**: In `[1, 4, 45, 6, 10, 8]`, the triplet `(1, 4, 45)` sums up to `50`.
    - **Hints**: Use three nested loops or a hash-based approach for efficient checking.

34. **Find the Longest Consecutive Sequence**
    - **Problem**: Identify the longest sequence of consecutive numbers in an array.
    - **Example**: For `[100, 4, 200, 1, 3, 2]`, the longest consecutive sequence is `[1, 2, 3, 4]`.
    - **Hints**: Use a hash set to check for consecutive numbers efficiently.

35. **Implement a Sparse Array**
    - **Problem**: Represent a sparse array (an array with many zero values) efficiently to save memory.
    - **Example**: Instead of storing `[0, 0, 3, 0, 5]`, store only the non-zero elements and their indices.
    - **Hints**: Use a struct or a pair of arrays to store values and their corresponding indices.
