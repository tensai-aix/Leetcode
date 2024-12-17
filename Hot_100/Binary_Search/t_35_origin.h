int search(int begin,int end,int* nums,int target){
    int mid = (begin + end) / 2;
    if(nums[mid] == target) return mid;
    if(begin == end || begin == end - 1){
        if(target > nums[end]) return end + 1;
        if(target < nums[begin]) return begin;
        return begin + 1;
    }
    if(target > nums[mid]) return search(mid + 1,end,nums,target);
    else return search(begin,mid - 1,nums,target);
}
int searchInsert(int* nums, int numsSize, int target) {
    return search(0,numsSize - 1,nums,target);
}