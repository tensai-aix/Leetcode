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
int find(int* nums,int begin,int end,int target,int div){
    if(end - begin <= 1){
        if(nums[end % div] == target) return end % div;
        if(nums[begin % div] == target) return begin % div;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(nums[mid % div] == target) return mid % div;
    if(target < nums[mid % div]) return find(nums,begin,mid - 1,target,div);
    else return find(nums,mid + 1,end,target,div);
}
int search(int* nums, int numsSize, int target) {
    int turning_point = findTurningPoint(nums,0,numsSize - 1,nums[0]);
    return find(nums,turning_point,turning_point + numsSize - 1,target,numsSize);
}