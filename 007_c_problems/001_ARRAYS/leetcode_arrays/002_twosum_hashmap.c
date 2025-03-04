#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int value;
	int key;
} hashmap_entry;

typedef struct{
	hashmap_entry* entries;
	int size;
	int capacity;
} hashmap;

void init_hashmap(hashmap* map, int capacity)
{
  map->entries = (hashmap_entry *) malloc(capacity * sizeof(hashmap_entry));
  map->size    = 0;
  map->capcity = capacity;
  
}

unsigned int hash(int key , int capacity)
{
   return key % capacity;
}

void put(haspmap* map, int key, int value )
{
  unsigned int index = hash(key, map->capacity);
  map->entries[index].key = key;
  map->entries[index].value = value;
  map->size++;


}

void get(hashmap* map; int key)
{
  unsigned int index = hash(key, map->capacity);
  

  return map->entries[index].value;

}




int* twosum(int* nums, int numsSize, int target, int* returnSize)
{

static int result[2];

    *returnSize =2;
    int* result = (int *) malloc(2 * sizeof(int) );

    for(int i=0; i<numsSize; i++){
      int complement = target - nums[i];

      

    
    }
  




}
int main()
{
	int nums[] = {2,7,11,15};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 9;

	int returnSize;

	// two sum
	
	int* result = twoSum(nums, 4, target, &returnSize);


	if(returnSize == 2){
	 printf("the indices --> [%d %d]\n",result[0],result[1]);
	}
	else{
	 printf("no match found \n");
	}



	free(result);

return 0;
}
