// 绕了弯路，因为adjust时，一路向上无法保证换下来的值大于其子值。另外时间复杂度高，精简版代码在final版本
#define get_left_child(i) i * 2 + 1
#define get_right_child(i) i * 2 + 2
#define get_parent(i) (i - 1) / 2

void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void down(int* nums,int numsSize,int index){
    int left = get_left_child(index);
    int right = get_right_child(index);
    if(left < numsSize && right < numsSize){
        if(nums[left] < nums[right] && nums[index] < nums[right]){
            swap(nums,index,right);
            down(nums,numsSize,right);
        }
        else if(nums[left] >= nums[right] && nums[index] < nums[left]){
            swap(nums,index,left);
            down(nums,numsSize,left);
        }
    }
    if(left == numsSize - 1 && nums[index] < nums[left]) swap(nums,index,left);
}
void adjust(int* nums,int numsSize){
    int tmp;
    for(int i = numsSize / 2;i >= 0;i--){
        down(nums,numsSize,i);
    }
}
void deleteTop(int* nums,int numsSize){
    nums[0] = nums[numsSize];
    down(nums,numsSize,0);
}
int findKthLargest(int* nums, int numsSize, int k) {
    adjust(nums,numsSize);
    for(int i = 1;i < k;i++){
        numsSize--;
        deleteTop(nums,numsSize);
    }
    return nums[0];
}