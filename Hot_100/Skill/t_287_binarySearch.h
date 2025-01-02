// 不是对数组本身进行二分查找，而是对1-n进行二分查找，分成两半，看看多的那部分在哪一半那

int find(int left,int right,int* nums,int numsSize){
    if(left == right) return left;
    int mid = (left + right) / 2;
    int count = 0;
    for(int i = 0;i < numsSize;i++){
        if(nums[i] >= left && nums[i] <= mid) count++;
    }
    if(count > mid - left + 1) return find(left,mid,nums,numsSize);
    return find(mid + 1,right,nums,numsSize);
}
int findDuplicate(int* nums, int numsSize) {
    return find(1,numsSize - 1,nums,numsSize);
}