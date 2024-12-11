// 很妙的解法，两边分别计算0到j的乘积和，再把两边合在一起就得到中间了。
#include <malloc.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int left[numsSize];
    int right[numsSize];
    left[0] = nums[0];
    right[0] = nums[numsSize - 1];
    for(int i=1;i<numsSize;i++){
        left[i] = left[i -1] * nums[i];
        right[i] = right[i - 1] * nums[numsSize - i- 1];
    }
    int* to_return = (int*) malloc (numsSize*sizeof(int));
    *returnSize = numsSize;
    to_return[0] = right[numsSize - 2];
    to_return[numsSize - 1] = left[numsSize - 2];
    for(int i=1;i<numsSize-1;i++){
        to_return[i] = left[i - 1] * right[numsSize - i -2];
    }
    return to_return;
}