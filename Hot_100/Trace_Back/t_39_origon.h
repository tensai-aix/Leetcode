// perfect in time and space
#include <malloc.h>
#include <stdlib.h>
#include <ssp/string.h>

int used[20];
int used_length;
int count;
int comp(const void *a, const void *b) {  
    return (*(int *)a - *(int *)b);  
} 
void build(int** ret,int* nums,int numsSize,int cur,int left,int* retSize){
    int val;
    for(int tmp = cur;tmp < numsSize;tmp++){
        val = nums[tmp];  
        if(val > left) break;
        used[used_length++] = val;
        if(val == left){
            retSize[count] = used_length;
            ret[count] = (int*) malloc (used_length * sizeof(int));
            memcpy(ret[count++],used,used_length * sizeof(int));
            used_length--;
            break;
        }
        else{  
            build(ret,nums,numsSize,tmp,left - val,retSize);
            used_length--;
        } 
    }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates,candidatesSize,sizeof(int),comp);
    int** ret = (int**) malloc (150 * sizeof(int*));
    (*returnColumnSizes) = (int*) malloc (150 * sizeof(int));
    used_length = 0;
    count = 0;
    build(ret,candidates,candidatesSize,0,target,*returnColumnSizes);
    (*returnSize) = count;
    return ret;
}