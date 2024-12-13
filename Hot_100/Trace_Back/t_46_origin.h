#include <malloc.h>
#include <ssp/string.h>

int cal(int length){
    int ret = 1;
    for (int i = 2; i <= length; i++){
        ret *= i;
    }
    return ret;
}
void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void build(int out_begin,int** ret,int in_begin,int in_end){
    if(in_begin >= in_end) return;
    int size = cal(in_end - in_begin);  // 一个分组的大小
    for(int i = in_begin;i <= in_end;i++){
        int tmp_begin = out_begin + (i - in_begin) * size;  // 外部偏移起始
        int tmp_end = tmp_begin + size;
        for(int j = tmp_begin;j < tmp_end;j++){
            swap(ret[j],in_begin,i);
        }
        build(tmp_begin,ret,in_begin + 1,in_end);
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = cal(numsSize);
    (*returnColumnSizes) = (int*) malloc ((*returnSize) * sizeof(int));
    for(int i = 0;i < (*returnSize);i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    int** ret = (int**) malloc ((*returnSize) * sizeof(int*));
    for(int i = 0;i < (*returnSize);i++){
        ret[i] = (int*) malloc (numsSize * sizeof(int));
        memcpy(ret[i],nums,numsSize * sizeof(int));
    }
    build(0,ret,0,numsSize - 1);
    return ret;
}