// 稍微优化了一下，用已有的sum去遍历，确实时间复杂度小了一点，但没小多少，哈哈
#include "uthash.h"

typedef struct{
    int sum;
    int* index;
    int index_num;
    int base_index_num;
    UT_hash_handle hh; 
}Hash;
int subarraySum(int* nums, int numsSize, int k){
    int to_return = 0;
    Hash* head = NULL;
    int cur_sum = 0;
    for(int i=-1;i < numsSize;i++){  // 引入-1作为起始项
        if(i >= 0) cur_sum += nums[i];
        Hash* out;
        HASH_FIND_INT(head,&cur_sum,out);
        if(!out){
            out = (Hash*) malloc (sizeof(Hash));
            out->sum = cur_sum;
            out->index_num = 0;  
            out->base_index_num = 2;
            out->index = (int*) malloc (2*sizeof(int));
            out->index[out->index_num++] = i;
            HASH_ADD_INT(head,sum,out);
        }
        else{
            out->index[out->index_num++] = i;
            if(out->index_num == out->base_index_num){
                out->base_index_num *= 2;
                int* new_index = (int*) realloc(out->index,out->base_index_num * sizeof(int));
                out->index = new_index;
            }
        }
    }
    Hash* now;
    Hash* next;
    HASH_ITER(hh,head,now,next){
        Hash* out;
        int to_find_sum = now->sum + k;
        HASH_FIND_INT(head,&to_find_sum,out);
        if(out){
            for(int i=0;i<out->index_num;i++){   // 调整遍历结构，方便break
                for(int j=0;j<now->index_num;j++){
                    if(now->index[j] < out->index[i]) to_return++;
                    else break;
                }
            }
        }
    }
    return to_return;
}