#include <malloc.h>
#include <math.h>

int rob(int* nums, int numsSize) {
    int* money = (int*) malloc (numsSize * sizeof(int));
    if(numsSize == 1) return nums[0];
    money[numsSize - 1] = nums[numsSize - 1];
    money[numsSize - 2] = fmax(nums[numsSize - 1],nums[numsSize - 2]);
    for(int j = numsSize - 3;j >= 0;j--){
        money[j] = fmax(nums[j] + money[j + 2],money[j + 1]);
    }
    return money[0];
}