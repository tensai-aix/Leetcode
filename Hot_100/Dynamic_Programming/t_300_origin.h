#include <math.h>

int lengthOfLIS(int* nums, int numsSize) {
    int cnt[numsSize];
    int tmp_val;
    cnt[0] = 1;
    int ret = 1;
    for(int i = 1;i < numsSize;i++){
        int minn = 0;
        tmp_val = nums[i];
        for(int j = 0;j < i;j++){
            if (nums[j] >= tmp_val) continue;
            minn = fmax(minn,cnt[j]);
        }
        cnt[i] = minn + 1;
        ret = fmax(ret,cnt[i]);
    }
    return ret;
}