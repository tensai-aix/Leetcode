// not pass,exceed time
#include <malloc.h>

# define MIN -10010
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = 0;
    int max = MIN;
    int max_index = -1;
    int* to_return = (int*) malloc ((numsSize - k + 1)*sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(nums[i] >= max){
            max = nums[i];
            max_index = i;
        }
        if(i < k){
            if(i == k-1) to_return[(*returnSize)++] = max;
            continue;
        }
        if(max_index == i-k){
            int tmp_max = MIN;
            int tmp_max_index = -1;
            for(int j=i-k+1;j<=i;j++){
                if(nums[j] >= tmp_max){
                    tmp_max = nums[j];
                    tmp_max_index = j;
                }
            }
            max = tmp_max;
            max_index = tmp_max_index;
        }
        to_return[(*returnSize)++] = max;
    }
    return to_return;  
}