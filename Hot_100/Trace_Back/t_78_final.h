// 思路：利用位运算，相应位上为1就加上对应的数字
#include <stdlib.h>

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    (*returnSize) = 1 << numsSize;
    (*returnColumnSizes) = (int*) calloc ((*returnSize),sizeof(int));
    int**ret = (int**) calloc ((*returnSize),sizeof(int*));
    int tmp;
    for(int i = 0;i < (*returnSize);i++){
        ret[i] = (int*) calloc (numsSize,sizeof(int));
        tmp = 1;
        for(int j = 0;j < numsSize;j++){
            if(i & tmp) ret[i][(*returnColumnSizes)[i]++] = nums[j];
            tmp <<= 1;
        }
    }
    return ret;
}