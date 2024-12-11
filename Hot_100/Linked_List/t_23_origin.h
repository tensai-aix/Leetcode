#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void merge(struct ListNode** lists,int left,int merge_size){
    int right = left + merge_size;
    struct ListNode* build = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* cur = build;
    struct ListNode* cur_left = lists[left];
    struct ListNode* cur_right = lists[right];
    while(true){
        if(cur_left == NULL){
            cur->next = cur_right;
            break;
        }
        else if(cur_right == NULL){
            cur->next = cur_left;
            break;
        }
        if(cur_left->val <= cur_right->val){
            cur->next = cur_left;
            cur_left = cur_left->next;
        }
        else{
            cur->next = cur_right;  
            cur_right = cur_right->next;
        }
        cur = cur->next;
    }
    lists[left] = build->next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(!listsSize) return NULL;
    int merge_size = 1;
    while(merge_size < listsSize){
        for(int index = 0;index < listsSize;index += (2 * merge_size)){
            if(index + merge_size >= listsSize) break;  // 右部为空
            merge(lists,index,merge_size);
        }
        merge_size *= 2;
    }
    return lists[0];
}