### **Optimized Solution Using Hashing (Prefix Sum + Hash Map)**

This approach uses a hash map to store the cumulative sum and check for subarrays in constant time.

### **Approach:**  
1. Maintain a cumulative sum (`current_sum`) as you iterate through the array.  
2. Use a hash map to store the count of all cumulative sums encountered so far.  
3. For each element, check if `current_sum - target` exists in the map.  
   - If it exists, it means there is a subarray with the desired sum.  
4. Track and print the subarrays using appropriate index calculations.  

---

### **C Code:**
```c
#include <stdio.h>
#include <stdlib.h>

// Structure to store hash table entries
typedef struct {
    int sum;
    int count;
} HashNode;

// Hash table implementation
#define TABLE_SIZE 1000

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(HashNode* table[], int sum) {
    int index = hash(sum);
    while (table[index] != NULL && table[index]->sum != sum) {
        index = (index + 1) % TABLE_SIZE;
    }
    if (table[index] == NULL) {
        table[index] = (HashNode*)malloc(sizeof(HashNode));
        table[index]->sum = sum;
        table[index]->count = 1;
    } else {
        table[index]->count++;
    }
}

int search(HashNode* table[], int sum) {
    int index = hash(sum);
    while (table[index] != NULL) {
        if (table[index]->sum == sum) {
            return table[index]->count;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return 0;
}

void findSubarraysWithSum(int arr[], int n, int target) {
    HashNode* hashTable[TABLE_SIZE] = {NULL};
    int current_sum = 0;

    // Insert initial sum (0) to handle subarrays starting from index 0
    insert(hashTable, 0);

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        int required_sum = current_sum - target;

        // Check if required_sum exists
        int count = search(hashTable, required_sum);
        if (count > 0) {
            printf("Subarray found ending at index %d\n", i);
        }

        // Insert current sum into the hash table
        insert(hashTable, current_sum);
    }

    // Free memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i]) free(hashTable[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int target = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findSubarraysWithSum(arr, n, target);
    return 0;
}
```

---

### **Explanation:**  
1. **Hash Table:** Efficiently tracks cumulative sums and checks if a previous sum exists to form a subarray.  
2. **current_sum - target:** This gives the starting index for the subarray if a match is found.  
3. **Multiple Subarrays:** If a sum appears more than once, multiple subarrays might exist.  

---

### **Complexity:**  
- **Time Complexity:** \( O(n) \) — Hash operations (insert and search) are \( O(1) \) on average.  
- **Space Complexity:** \( O(n) \) — For storing cumulative sums in the hash table.  

