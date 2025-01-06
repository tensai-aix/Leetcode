void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void down(int* nums,int numsSize,int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if(left < numsSize && nums[left] > nums[largest]){
        largest = left;
    }
    if(right < numsSize && nums[right] > nums[largest]){
        largest = right;
    }
    if(largest != index){
        swap(nums,index,largest);
        down(nums,numsSize,largest);
    }
}
void adjust(int* nums,int numsSize){
    for(int i = numsSize / 2 - 1;i >= 0;i--){
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