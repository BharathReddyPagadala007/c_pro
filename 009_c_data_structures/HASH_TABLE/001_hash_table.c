#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct HashNode{
	int key;
	int value;
	struct HashNode* next;
}HashNode;

#define TABLE_SIZE 10

typedef struct HashTable{

	HashNode* buckets[TABLE_SIZE];
}HashTable;

int hashFunction(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; // Handles negative keys
}


HashTable* createHashTable(){
  HashTable* table = (HashTable*)malloc(sizeof(HashTable));

  for(int i=0; i< TABLE_SIZE; i++){
  	table->buckets[i] = NULL;
  }
return table;
}

void insert(HashTable* table, int key, int value){
   int index= hashFunction(key);
   HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
   newNode->key = key;
   newNode->value = value;
   newNode->next = table->buckets[index];
   table->buckets[index]= newNode;
}

int  search(HashTable* table, int key){

   int index = hashFunction(key);
   HashNode* current = table->buckets[index];

   while(current){
	   if(current->key == key)
	   {
	     return current->value;
	   }
	   current = current->next;
   
   }

   return -1;

}

void deleteKey(HashTable* table, int key){

	int index = hashFunction(key);
	HashNode* current = table->buckets[index];
	HashNode* prev = NULL;

	while(current){
		if(current->key == key){
		  if(prev){
		   prev->next = current->next;
		  }else{
		  table->buckets[index] = current->next;
		  }
		  free(current);
		  return;
		}
		prev = current;
		current = current->next;
	}
}


void printHashTable(HashTable* table){
	for(int i=0; i<TABLE_SIZE; i++){
	
		printf("BUcket %d :: ",i);
		HashNode* current = table->buckets[i];

		while(current){
			printf("(%d, %d)",current->key,current->value);
			current = current->next;
		
		}
		printf("NULL\n");
	
	}


}



int main() {
    HashTable* table = createHashTable();
    
    insert(table, 1, 10);
    insert(table, 11, 20);
    insert(table, 21, 30);
    insert(table, 23, 30);
    insert(table, 25, 30);

    printf("Hash Table:\n");
    printHashTable(table);

    printf("Search for key 11: %d\n", search(table, 11)); // Output: 20
    printf("Search for key 5: %d\n", search(table, 5));   // Output: -1

    printf("Deleting key 11\n");
    deleteKey(table, 11);

    printf("Hash Table after deletion:\n");
    printHashTable(table);

    return 0;
}
