void rotate(int* nums, int numsSize, int k) {
    int tmp;
    int cur_next = k % numsSize;
    int cur = 0;
    for(int i=1;i<numsSize;i++){ // 要进行numsSize-1次变换
        tmp = nums[cur];
        nums[cur] = nums[cur_next];
        nums[cur_next] = tmp;
        cur_next = (cur_next + k) % numsSize;
        if(cur == cur_next){  // 要换的位置已经是现在的位置了
            cur++; 
            cur_next = (cur + k) % numsSize;
            i++;
        }
    }
}
