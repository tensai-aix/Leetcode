// pass,but too long,o(n^2)
# include "uthash.h"

typedef struct t
{
    int key;
    int Size;
    int index;
    UT_hash_handle hh;  // 一定要命名为hh
}Hash;

void add_value(int array[][3],int index,int a,int b,int c){
    array[index][0] = a;
    array[index][1] = b;
    array[index][2] = c;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    Hash* head=NULL;
    int index = 0;
    int return_size = 0;
    int return_array[5000000][3];
    for(int i=0;i<numsSize;i++){
        Hash* tmp;
        int to_find_number = nums[i];
        HASH_FIND_INT(head,&to_find_number,tmp);
        if(!tmp){
            tmp = (Hash*) malloc (sizeof(Hash));
            tmp->key = to_find_number;
            tmp->Size = 1;
            tmp->index = index;
            index++;
            HASH_ADD_INT(head,key,tmp);
        }
        else tmp->Size++;
    }
    Hash* out_now;
    Hash* out_next;
    Hash* inner_now;
    Hash* inner_next;
    HASH_ITER(hh,head,out_now,out_next){
        // 三个0
        if (out_now->key == 0 && out_now->Size >= 3){
            return_size++;
            add_value(return_array,return_size-1,0,0,0);
        }
        // 两个相同
        if(out_now->key !=0 && out_now->Size >= 2){
            int to_find_number = 0 - out_now->key*2;
            Hash* tmp;
            HASH_FIND_INT(head,&to_find_number,tmp);
            if(tmp){
                return_size++;
                add_value(return_array,return_size-1,out_now->key,out_now->key,tmp->key);
            }           
        }
        // 三个都不同
        HASH_ITER(hh,out_next,inner_now,inner_next){
            int to_find_number = 0 - out_now->key - inner_now->key;
            Hash* tmp;
            HASH_FIND_INT(head,&to_find_number,tmp);
            if(!tmp || tmp->index <= inner_now->index) continue;
            return_size++;
            add_value(return_array,return_size-1,out_now->key,inner_now->key,tmp->key);
        }
    }
    *returnSize = return_size;
    (*returnColumnSizes) = (int*) malloc (return_size*sizeof(int));
    int** returned = (int**) malloc (return_size*sizeof(int*));
    for(int i=0;i<return_size;i++){
        (*returnColumnSizes)[i] = 3;
        returned[i] = (int*) malloc (3*sizeof(int));
        memcpy(returned[i],return_array[i],3*sizeof(int));
    }
    return returned;
}


// 标准思路：先将数组从小到大排序，然后固定住数组的第i个元素（作为三元组里最小的），并设立双指针，首尾相加，小了移动left，大了移动right
// 优化：剪枝，跳过重复的。对于i，若重复，直接跳过，左右指针也跳过重复元素