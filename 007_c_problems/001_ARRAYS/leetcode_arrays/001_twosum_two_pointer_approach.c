#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int num;
  int index;
}N_num_index_hash;

int compare(const void* a, const void* b) {
    return ((N_num_index_hash *) a)->num - ((N_num_index_hash *)b)->num;
}

int * twosum(int* nums, int  numsSize, int target, int* returnSize){
    
	N_num_index_hash  numbers[numsSize];

	for(int i=0; i<numsSize; i++){
		numbers[i].num= nums[i];
		numbers[i].index=i;
	}


	//qsort
	
	qsort(numbers,numsSize,sizeof(N_num_index_hash),compare);


	int left=0, right= numsSize-1;
	
 while(left < right) {
        int sum = numbers[left].num + numbers[right].num;
        if(sum == target) {
            *returnSize = 2;
            int* result = (int*)malloc(*returnSize * sizeof(int));
            result[0] = numbers[left].index;
            result[1] = numbers[right].index;
            return result;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }


return NULL;

}


int main()
{

  int nums[] = {1,3,7,2,6,3};
  int numsSize = sizeof(nums)/sizeof(nums[0]);

  int target =10;

  int * result;
int  returnSize=0;

  result =twosum(nums,numsSize,target,&returnSize);

  printf("%d %d \n",result[0],result[1]);




return 0;
}
