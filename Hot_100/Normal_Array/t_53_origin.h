#include <math.h>

int maxSubArray(int* nums, int numsSize) {
    int to_return = nums[0];   
    int cur_sum = 0;
    for(int right = 0;right<numsSize;right++){
        cur_sum += nums[right];
        if(cur_sum > to_return){
            to_return = cur_sum;
        } 
        if(cur_sum < 0) cur_sum = 0;  // 小于0直接斩掉，重新找可能的最大值
    }
    return to_return; 
}