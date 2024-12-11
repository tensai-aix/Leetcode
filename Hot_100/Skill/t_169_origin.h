int majorityElement(int* nums, int numsSize) {
    int cnt = 1;
    int max = nums[0];
    for(int i=1;i<numsSize;i++){
        if(nums[i] == max) cnt++;
        else cnt--;
        if(cnt < 0) {
            max = nums[i];
            cnt = 1;
        }
    }
    return max;
}