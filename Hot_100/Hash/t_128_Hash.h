# include "uthash.h"

typedef struct t
{
    int key;
    UT_hash_handle hh;  // 一定要命名为hh
}Hash;

int longestConsecutive(int* nums, int numsSize) {
    Hash* head = NULL;
    // 插入哈希表
    for(int i=0;i<numsSize;i++){
        Hash* tmp = NULL;
        int to_insert_number = nums[i];
        HASH_FIND_INT(head,&to_insert_number,tmp);
        if(!tmp){
            tmp = (Hash*) malloc (sizeof(Hash));
            tmp->key = to_insert_number;
            HASH_ADD_INT(head,key,tmp);
        }
    }
    int returned = 0;
    Hash* now = NULL;
    Hash* next = NULL;
    // 遍历哈希表
    HASH_ITER(hh,head,now,next){
        Hash* tmp = NULL;
        int to_find_number = now->key-1;   // 很聪明的一个技巧，若num-1存在，说明num不是最小，则跳过
        HASH_FIND_INT(head,&to_find_number,tmp);
        if(tmp) continue;
        int tmp_number=0;
        to_find_number++;
        do{
            tmp_number++;
            to_find_number++;
            HASH_FIND_INT(head,&to_find_number,tmp);
        }while(tmp);
        if(tmp_number>returned) returned = tmp_number;
    }
    return returned;
}
