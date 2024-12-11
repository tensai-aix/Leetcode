#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int length = 0;
    struct ListNode** Queue = (struct ListNode**) malloc (k*sizeof(struct ListNode*));
    for(struct ListNode* tmp = head;tmp!=NULL;tmp=tmp->next) length++;
    struct ListNode* to_return = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* cur = to_return;
    int to_deal = length / k;
    for(int i=0;i<to_deal;i++){
        for(int j=0;j<k;j++){
            Queue[j] = head;
            head = head->next;
        }
        for(int j=k-1;j>=0;j--){
            cur->next = Queue[j];
            cur = cur->next;
        }
    }
    cur->next = head;
    return to_return->next;
}