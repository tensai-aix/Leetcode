int findTurningPoint(int* nums,int begin,int end,int target){
    if(end - begin <= 1){
        if(nums[begin] < target) return begin;
        else if(nums[end] < target) return end;
        return 0;
    }
    int mid = (begin + end) / 2;
    if(target < nums[mid]) return findTurningPoint(nums,mid + 1,end,target);
    else return findTurningPoint(nums,begin,mid,target);
}
int findMin(int* nums, int numsSize) {
    int turning_point = findTurningPoint(nums,0,numsSize - 1,nums[0]);
    return nums[turning_point];
}