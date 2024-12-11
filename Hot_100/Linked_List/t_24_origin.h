#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* to_return = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* cur = to_return;
    struct ListNode* head_next;
    struct ListNode* to_jump;
    while(true){
        if(!head) break;
        head_next = head->next;
        if(head && !head_next){
            cur->next = head;
            cur = cur->next; 
            break;
        }
        to_jump = head_next->next;
        cur->next = head_next;
        cur = cur->next;
        cur->next = head;
        cur = cur->next;
        head = to_jump;     
    }
    cur->next = NULL;
    return to_return->next; 
}