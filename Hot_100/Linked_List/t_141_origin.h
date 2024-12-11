// pass,not problem in idea,but slow
#include <uthash.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct HASH{
    struct ListNode* node;
    UT_hash_handle hh;
}Hash;
bool hasCycle(struct ListNode *head) {
    Hash* head_hash = NULL;
    if(head == NULL) return false;
    while(true){
        Hash* to_insert = (Hash*) malloc (sizeof(Hash));
        to_insert->node = head;
        HASH_ADD_PTR(head_hash,node,to_insert);
        if(head->next == NULL) return false;
        Hash* out;
        HASH_FIND_PTR(head_hash,&head->next,out);
        if(out) return true;
        head = head->next;
    }
}

// 看到一个有意思的解法，快慢指针，快指针一次走两步，慢指针一次走一步，如果快指针到达null说明肯定无环，否则审查快慢指针是否会相遇