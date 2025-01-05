#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {  
    int sum = 0;
    for(int i = 0;i < numsSize;i++){
        sum += nums[i];
    }
    if(sum % 2 == 1) return false;
    sum = sum / 2;
    int reach[sum + 1];
    reach[0] = 1;
    for(int j = 1;j <= sum;j++){
        reach[j] = 0;
    }
    int tmp1,tmp2;
    for(int i = 0;i < numsSize;i++){
        tmp1 = nums[i];
        for(int j = 0;j < sum;j++){
            tmp2 = j + tmp1;
            if(reach[j] == 1 && tmp2 <= sum && reach[tmp2] == 0) reach[tmp2] = 2;
        }
        for(int j = 0;j < sum;j++){
            tmp2 = j + tmp1;
            if(tmp2 <= sum && reach[tmp2] == 2) reach[tmp2] = 1;
        }
    }
    return reach[sum] == 1;
}