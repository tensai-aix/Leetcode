#include <malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* returned_array = (int*) malloc (2*sizeof(int));
    for(int i=0;i<numsSize;i++){
        int tmp = target - nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(tmp == nums[j]){
                returned_array[0] = i;
                returned_array[1] = j;
                return returned_array;
            }
        }
    }
    return returned_array;
}