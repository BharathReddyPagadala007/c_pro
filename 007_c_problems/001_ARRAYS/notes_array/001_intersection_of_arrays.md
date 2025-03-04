The **Intersection of Two Arrays** problem can be solved using different approaches depending on the complexity you want. Here's a breakdown of common approaches:

---

### Problem Statement:
Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be unique, and you may return the result in any order.

---

### **Approach 1: Brute Force (O(n^2))**
- Compare each element of `nums1` with every element in `nums2` and store matches.
- Use an auxiliary structure (like a set) to avoid duplicates.

#### **C Code**:
```c
#include <stdio.h>
#include <stdlib.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    int resultCount = 0;

    for (int i = 0; i < nums1Size; i++) {
        int found = 0;
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                found = 1;
                break;
            }
        }
        if (found) {
            int unique = 1;
            for (int k = 0; k < resultCount; k++) {
                if (result[k] == nums1[i]) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                result[resultCount++] = nums1[i];
            }
        }
    }
    *returnSize = resultCount;
    return result;
}
```

---

### **Approach 2: Using Sorting and Two Pointers (O(n log n + m log m))**
- Sort both arrays.
- Use two pointers to find the intersection.

#### **C++ Code**:
```cpp
#include <vector>
#include <algorithm>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> result;

    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return result;
}
```

---

### **Approach 3: Using Hash Set (O(n + m))**
- Use a hash set to store elements of `nums1` and check against `nums2`.

#### **Python Code**:
```python
def intersection(nums1, nums2):
    set1 = set(nums1)
    set2 = set(nums2)
    return list(set1 & set2)
```

---

### **Approach 4: Using Hash Map (O(n + m))**
- Use a hash map to count elements and filter results uniquely.

#### **C++ Code**:
```cpp
#include <unordered_set>
#include <vector>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set(nums1.begin(), nums1.end());
    std::unordered_set<int> result;

    for (int num : nums2) {
        if (set.find(num) != set.end()) {
            result.insert(num);
        }
    }
    return std::vector<int>(result.begin(), result.end());
}
```

---

### **Approach 5: Binary Search (O(n log m) or O(m log n))**
- If one array is much smaller, sort the larger array and perform binary search for each element of the smaller array.

#### **Python Code**:
```python
import bisect

def intersection(nums1, nums2):
    nums2.sort()
    result = set()
    for num in nums1:
        if bisect.bisect_left(nums2, num) < len(nums2) and nums2[bisect.bisect_left(nums2, num)] == num:
            result.add(num)
    return list(result)
```

---

### Complexity Comparison:
| Approach               | Time Complexity  | Space Complexity |
|-------------------------|------------------|------------------|
| Brute Force            | \(O(n \times m)\) | \(O(min(n, m))\) |
| Sorting + Two Pointers | \(O(n \log n + m \log m)\) | \(O(n + m)\) |
| Hash Set               | \(O(n + m)\)     | \(O(n + m)\)     |
| Hash Map               | \(O(n + m)\)     | \(O(n + m)\)     |
| Binary Search          | \(O(n \log m)\)  | \(O(n)\)         |

---

These implementations give flexibility depending on the size of input arrays and performance constraints.
