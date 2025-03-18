
### **Fixed Size Sliding Window**
1. **Maximum sum of a subarray of size `k`**  
   - Given an array of integers and a number `k`, find the maximum sum of any contiguous subarray of size `k`.
   - **Example**:  
     ```
     Input: arr = [2, 1, 5, 1, 3, 2], k = 3
     Output: 9  (subarray [5, 1, 3])
     ```

2. **First negative number in every window of size `k`**  
   - Given an array of integers (which can have negative numbers) and a number `k`, find the first negative number in every window of size `k`. If no negative number exists in a window, return `0` for that window.
   - **Example**:  
     ```
     Input: arr = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
     Output: [-1, -1, -7, -15, -15, 0]
     ```

3. **Find the average of each subarray of size `k`**  
   - Given an array and an integer `k`, compute the average of every contiguous subarray of size `k`.
   - **Example**:  
     ```
     Input: arr = [1, 3, 2, 6, -1, 4, 1, 8, 2], k = 5
     Output: [2.2, 2.8, 2.4, 3.6, 2.8]
     ```


### **Variable Size Sliding Window**
4. **Smallest subarray with a sum greater than `S`**  
   - Given an array of positive integers, find the length of the smallest contiguous subarray whose sum is greater than or equal to `S`.
   - **Example**:  
     ```
     Input: arr = [2, 1, 5, 2, 3, 2], S = 7
     Output: 2  (subarray [5, 2])
     ```

5. **Longest subarray with sum `≤ K`**  
   - Given an array and an integer `K`, find the length of the longest contiguous subarray whose sum does not exceed `K`.
   - **Example**:  
     ```
     Input: arr = [3, 1, 2, 7, 4, 2, 1, 1, 5], K = 8
     Output: 4  (subarray [3, 1, 2, 7] is too large, so [4, 2, 1, 1] is the longest valid subarray)
     ```

6. **Longest substring with at most `K` distinct characters**  
   - Given a string and an integer `K`, find the length of the longest substring with at most `K` distinct characters.
   - **Example**:  
     ```
     Input: str = "araaci", K = 2
     Output: 4  ("araa")
     ```

7. **Longest substring with all unique characters (Longest Substring Without Repeating Characters)**  
   - Given a string, find the length of the longest substring without repeating characters.
   - **Example**:  
     ```
     Input: str = "abcabcbb"
     Output: 3  ("abc")
     ```

---

### **Advanced Sliding Window**
8. **Longest subarray with equal number of `0s` and `1s`**  
   - Given a binary array containing only `0s` and `1s`, find the length of the longest contiguous subarray that has an equal number of `0s` and `1s`.
   - **Example**:  
     ```
     Input: arr = [0, 1, 0, 1, 1, 1, 0]
     Output: 6  (subarray [0, 1, 0, 1, 1, 1] is the longest)
     ```

9. **Find the maximum of every subarray of size `k`** (Sliding Window Maximum)  
   - Given an array, find the maximum element in every contiguous subarray of size `k`.
   - **Example**:  
     ```
     Input: arr = [1,3,-1,-3,5,3,6,7], k = 3
     Output: [3,3,5,5,6,7]
     ```

10. **Longest subarray with sum exactly equal to `K`**  
    - Given an array and an integer `K`, find the length of the longest contiguous subarray whose sum equals `K`.
    - **Example**:  
      ```
      Input: arr = [4, 1, 1, 1, 2, 3, 5], K = 5
      Output: 4  (subarray [1, 1, 1, 2])
      ```

