// fail,没能处理好位置分配
#include <malloc.h>
#include <cstddef>

int cal(int base,int point){
    if(point > base / 2) return cal(base,base - point);
    int ret = 1;
    int del = 1;
    for(int i = 1;i <= point;i++,base--){
        ret *= base;
        del *= i;
    }
    return ret/del;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int* step = (int*) malloc ((numsSize + 1) * sizeof(int));
    (*returnSize) = 1 << numsSize;
    (*returnColumnSizes) = (int*) calloc ((*returnSize),sizeof(int));
    for(int i = 0;i <= numsSize;i++){
        step[i] = cal(numsSize,i);
    }
    int** ret = (int**) calloc ((*returnSize),sizeof(int*));
    int base = 1;
    for(int group = 1;group <= numsSize;group++){
        for(int i = 0;i < step[group];i++){
            ret[i + base] = (int*) malloc (group * sizeof(int));
        }
        base += step[group];
    }
    ret[0] = NULL;
    base = 1;
    int repeat_time,add,begin,cur;
    for(int group = 1;group <= numsSize;group++){
        begin = 0;
        for(int num_no = 0;num_no < numsSize;num_no++){
            cur = 0;
            repeat_time = group * step[group] / numsSize;
            for(int i = 0;i < repeat_time;i++){        
                add = (begin % step[group]) + base;
                ret[add][(*returnColumnSizes)[add]++] = nums[num_no];
                begin += numsSize;
                cur = (cur + numsSize) % step[group];
                if(cur == 0) begin++;
            }
        }
        base += step[group];
    }
    return ret;
}