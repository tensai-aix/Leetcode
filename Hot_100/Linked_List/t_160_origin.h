#include "uthash.h"
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct HASH{
    struct ListNode* node;
    UT_hash_handle hh;
}Hash;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    Hash* head = NULL;
    if(headA == NULL || headB == NULL) return NULL;
    struct ListNode* tmp;
    for(tmp=headA;tmp!=NULL;tmp=tmp->next){
        Hash* to_insert = (Hash*) malloc (sizeof(Hash));
        to_insert->node = tmp;
        HASH_ADD_PTR(head,node,to_insert);
    }
    for(tmp=headB;tmp!=NULL;tmp=tmp->next){
        Hash* out;
        HASH_FIND_PTR(head,&tmp,out);
        if(out) return out->node;
    }
    return NULL;
}