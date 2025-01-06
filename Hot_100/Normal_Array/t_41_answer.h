// 思路是把相应的正数放在相应的位置上，然后检查哪个对不上
// 另外题解忽略了一个测试用例：{2，1}

void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int firstMissingPositive(int* nums, int numsSize) {
    int tmp,i;
    for(i = 0;i < numsSize;i++){
        if(nums[i] < 1 || nums[i] > numsSize || nums[nums[i] - 1] == nums[i]) continue;
        swap(nums,i,nums[i] - 1);
        i--;
    }
    for(i = 0;i < numsSize;i++){
        if(nums[i] != i + 1) break;
    }
    return i + 1;
}