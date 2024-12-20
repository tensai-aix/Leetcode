bool canJump(int* nums, int numsSize) {
    int reach = 0;
    for(int i = 0;i < numsSize;i++){
        if(i <= reach){
            if(i + nums[i] > reach) reach = i + nums[i];
            if(reach >= numsSize - 1) return true;
        }  
        else return false;
    }
    return false;
}