#include <malloc.h>

int findMin(int* nums,int begin,int end,int target){
    if(end - begin <= 1){
        if(nums[begin] == target) return begin;
        if(nums[end] == target) return end;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target <= nums[mid]) return findMin(nums,begin,mid,target);
    else return findMin(nums,mid + 1,end,target);
}
int findMax(int* nums,int begin,int end,int target){
    if(end - begin <= 1){
        if(nums[end] == target) return end;
        if(nums[begin] == target) return begin;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target >= nums[mid]) return findMax(nums,mid,end,target);
    else return findMax(nums,begin,mid - 1,target);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    (*returnSize) = 2;
    int* ret = (int*) malloc (2 * sizeof(int));
    if(!numsSize){
        ret[0] = -1;
        ret[1] = -1;
        return ret;
    }
    ret[0] = findMin(nums,0,numsSize - 1,target);
    if(ret[0] < 0){
        ret[1] = -1;
        return ret;
    } 
    ret[1] = findMax(nums,0,numsSize - 1,target);
    return ret;
}