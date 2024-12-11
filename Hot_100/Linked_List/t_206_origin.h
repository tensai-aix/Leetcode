#include <cstddef>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct STACK{
    struct ListNode* node[5010];
    int number;
}Stack;
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) return NULL;
    Stack stack;
    stack.number = 0;
    for(struct ListNode* tmp = head;tmp!=NULL;tmp=tmp->next){
        stack.node[stack.number++] = tmp;
    }
    struct ListNode* rehead = stack.node[--stack.number];
    struct ListNode* tmp = rehead;
    while(stack.number > 0){
        tmp->next = stack.node[--stack.number];
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return rehead;
}