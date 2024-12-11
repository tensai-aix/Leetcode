#include <malloc.h>
#include <ssp/string.h>

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int min = 10010;
    int max = -1;
    for(int i=0;i<intervalsSize;i++){
        if(intervals[i][0] < min) min = intervals[i][0];
        if(intervals[i][1] > max) max = intervals[i][1];
    }
    int length = max - min + 1;
    int* exist = (int*) calloc (length,sizeof(int));  // 0是不存在，1是中间项，2是起始项，3是结束项，4是孤立项
    int left,right;
    for(int i=0;i<intervalsSize;i++){
        left = intervals[i][0] - min;
        right = intervals[i][1] - min;
        if(left != right){
            if(!exist[left] || exist[left] == 4) exist[left] = 2;
            else if(exist[left] == 3) exist[left] = 1;
            if(!exist[right] || exist[right] == 4) exist[right] = 3;
            else if(exist[right] == 2) exist[right] = 1;
        }
        if(!exist[left] && left == right) exist[left] = 4;
        for(int j=left+1;j<right;j++) exist[j] = 1;
    }
    int cur = 0;
    int cur_last;
    int collect[10010][2];
    (*returnSize) = 0;
    while(true){
        if(exist[cur] == 2){
            for(cur_last = cur + 1;;cur_last++){
                if(exist[cur_last] == 3) break;
            }
            collect[(*returnSize)][0] = cur + min;
            collect[(*returnSize)++][1] = cur_last + min;
            cur = cur_last;
        }
        else if(exist[cur] == 4){
            collect[(*returnSize)][0] = cur + min;
            collect[(*returnSize)++][1] = cur + min;
        }
        if((++cur) == length) break;
    }
    int** to_return = (int**) malloc ((*returnSize) * sizeof(int*));
    (*returnColumnSizes) = (int*) malloc((*returnSize)*sizeof(int));
    for(int i=0;i<(*returnSize);i++){
        (*returnColumnSizes)[i] = 2;
        to_return[i] = (int*) malloc (2 * sizeof(int));
        memcpy(to_return[i],collect[i],2 * sizeof(int));
    }
    return to_return;
}