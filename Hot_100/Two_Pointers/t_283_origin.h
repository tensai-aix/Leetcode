#include <malloc.h>
#include <ssp/string.h>

void moveZeroes(int* nums, int numsSize) {
    if(!numsSize) return;
    int index=0;
    int* new_num = (int*) calloc (numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++){
        int to_deal_number = nums[i];
        if(to_deal_number!=0){
            new_num[index] = to_deal_number;
            index++;
        }
    }
    memcpy(nums,new_num,numsSize*sizeof(int));
}