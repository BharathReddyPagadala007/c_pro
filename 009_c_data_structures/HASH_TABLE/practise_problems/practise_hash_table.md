---

### **Problem 1: Implement a Simple Hash Table**
Write a basic hash table in C with the following features:
- Keys are strings, and values are integers.
- Use an array for storage with separate chaining (linked list) for collision handling.
- Include functions for insertion, searching, and deletion.

---

### **Problem 2: Count Frequency of Elements**
Given an array of integers, count the frequency of each element using a hash table.

**Input:**  
`arr = [5, 3, 5, 2, 8, 3, 3]`  

**Output:**  
`5: 2, 3: 3, 2: 1, 8: 1`

---

### **Problem 3: Find Pairs with Given Sum**
Given an array of integers, find all unique pairs of elements that sum to a given value.

**Input:**  
`arr = [1, 5, 7, -1, 5]`, `target = 6`

**Output:**  
Pairs: `(1, 5), (7, -1)`

---

### **Problem 4: Check if Two Strings are Anagrams**
Use a hash table to determine if two strings are anagrams of each other. Ignore spaces and consider case insensitivity.

**Input:**  
`str1 = "Listen", str2 = "Silent"`

**Output:**  
`True`

---

### **Problem 5: First Non-Repeating Character**
Find the first non-repeating character in a string using a hash table.

**Input:**  
`str = "swiss"`

**Output:**  
`w`

---

### **Problem 6: Two Sum Problem**
Find two numbers in an array such that their sum is equal to a target value. Use a hash table to achieve O(n) time complexity.

**Input:**  
`arr = [2, 7, 11, 15]`, `target = 9`

**Output:**  
`Indices: (0, 1)`

---

### **Problem 7: Subarray with Given Sum**
Find if there exists a subarray with a sum equal to a given value.

**Input:**  
`arr = [1, 4, 20, 3, 10, 5]`, `target = 33`

**Output:**  
`True (subarray [20, 3, 10])`

---

### **Problem 8: Implement LRU Cache**
Design an LRU (Least Recently Used) cache using a hash table and a doubly linked list.

**Functions to Implement:**
- `get(key)`: Fetch the value of the key if it exists in the cache, else return -1.
- `put(key, value)`: Insert a key-value pair into the cache. If the cache exceeds capacity, evict the least recently used item.

---

