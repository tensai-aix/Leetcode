# include "uthash.h"

typedef struct t{
    int key;
    int cnt;
    UT_hash_handle hh;  
}Hash;
Hash* head;
void swap(Hash** heap,int i,int j){
    Hash* tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}
void UP(Hash** heap,int index){
    int parent = (index - 1) / 2;
    while(parent >= 0 && heap[index]->cnt < heap[parent]->cnt){
        swap(heap,index,parent);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void DOWN(Hash** heap,int heap_size,int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int minn = index;
    if(left < heap_size && heap[left]->cnt < heap[minn]->cnt){
        minn = left;
    }
    if(right < heap_size && heap[right]->cnt < heap[minn]->cnt){
        minn = right;
    }
    if(minn != index){
        swap(heap,index,minn);
        DOWN(heap,heap_size,minn);
    }
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    head = NULL;
    Hash* tmp;
    for(int i = 0;i < numsSize;i++){
        HASH_FIND_INT(head,nums + i,tmp);
        if(tmp) tmp->cnt++;
        else{
            tmp = (Hash*) malloc (sizeof(Hash));
            tmp->cnt = 1;
            tmp->key = nums[i];
            HASH_ADD_INT(head,key,tmp);
        }
    }
    Hash** heap = (Hash**) malloc (k * sizeof(Hash*));
    int heap_size = 0;
    Hash* now = NULL;
    HASH_ITER(hh,head,now,tmp){
        if(heap_size < k){
            heap[heap_size++] = now;
            UP(heap,heap_size - 1);
        }
        else{
            if(now->cnt > heap[0]->cnt){
                heap[0] = now;
                DOWN(heap,heap_size,0);
            }
        }
    }
    int* ret = (int*) malloc (k * sizeof(int));
    for(int i = 0;i < k;i++){
        ret[i] = heap[i]->key;
    }
    (*returnSize) = k;
    return ret;
}
