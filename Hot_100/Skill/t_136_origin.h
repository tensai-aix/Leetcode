#include <stdint.h>

int singleNumber(int* nums, int numsSize) {
    int to_return = 0;
    for(int i=0;i<numsSize;i++) to_return ^= nums[i];
    return to_return;
}