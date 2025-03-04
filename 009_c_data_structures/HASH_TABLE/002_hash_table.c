#include <stdio.h>
#include <stdlib.h>

// Define the hash node structure
typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next; // For chaining in case of collisions
} HashNode;

// Define the hash table structure
typedef struct HashTable {
    HashNode **buckets;
    int size;
} HashTable;

// Hash function for integer keys
unsigned int hash(int key, int size) {
    return key % size;
}

// Create a hash table
HashTable *createHashTable(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (HashNode **)calloc(size, sizeof(HashNode *));
    return table;
}

// Insert a key-value pair
void insert(HashTable *table, int key, int value) {
    unsigned int index = hash(key, table->size);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table->buckets[index];
    table->buckets[index] = newNode;
}

// Retrieve a value by key
int get(HashTable *table, int key) {
    unsigned int index = hash(key, table->size);
    HashNode *node = table->buckets[index];
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

// Free memory
void freeHashTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        HashNode *node = table->buckets[i];
        while (node) {
            HashNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// Example usage
int main() {
    HashTable *table = createHashTable(10);

    insert(table, 1, 42);
    insert(table, 2, 56);
    insert(table, 3, 78);
    insert(table, 12, 99); // Collision with key 2 (12 % 10 = 2)

    printf("Value for key 1: %d\n", get(table, 1));
    printf("Value for key 2: %d\n", get(table, 2));
    printf("Value for key 3: %d\n", get(table, 3));
    printf("Value for key 12: %d\n", get(table, 12)); // Collision resolved via chaining
    printf("Value for key 4: %d\n", get(table, 4));  // Not found

    freeHashTable(table);
    return 0;
}

