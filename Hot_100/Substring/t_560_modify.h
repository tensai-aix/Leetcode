// 技巧点：动态分配内存，当发现列表大小与base相同时，就重新分配大小（也可以超了再分配）.用哈希表储存0到i的和，然后判断和之差等于k即可。
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
    for(int i=0;i < numsSize;i++){
        cur_sum += nums[i];
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
    cur_sum = 0;
    for(int i=0;i<numsSize;i++){
        int to_find_sum = cur_sum + k;
        cur_sum += nums[i];
        Hash* out;
        HASH_FIND_INT(head,&to_find_sum,out);
        if(!out) continue;
        for(int j=0;j<out->index_num;j++){
            if(out->index[j] >= i) to_return++;  // 本质上不能重合，两个下标得有差异
        }
    } 
    return to_return;
}