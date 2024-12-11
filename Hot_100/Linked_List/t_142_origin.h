#include <uthash.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct HASH{
    struct ListNode* node;
    UT_hash_handle hh;
}Hash;
struct ListNode *detectCycle(struct ListNode *head) {
    Hash* head_hash = NULL;
    if(head == NULL) return NULL;
    while(true){
        Hash* to_insert = (Hash*) malloc (sizeof(Hash));
        to_insert->node = head;
        HASH_ADD_PTR(head_hash,node,to_insert);
        if(head->next == NULL) return NULL;
        Hash* out;
        HASH_FIND_PTR(head_hash,&head->next,out);
        if(out) return out->node;
        head = head->next;
    }
}