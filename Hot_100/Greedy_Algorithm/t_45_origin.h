int jump(int* nums, int numsSize) {
    if(numsSize == 1) return 0;
    int step = 1;
    int s_begin = 0;
    int s_end = 0;
    int cur = 0;
    int reach = 0;
    while(true){
        for(cur = s_begin;cur <= s_end;cur++){
            if(cur + nums[cur] > reach) reach = cur + nums[cur];
            if(reach >= numsSize - 1) return step;
        }
        s_begin = s_end + 1;
        s_end = reach;
        step++;
    }
}