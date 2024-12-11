#include <cstddef>
#include <math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct STACK{
    int num[110];
    int length;
}Stack;
int Getnum(Stack stack,int i){
    if(i >= stack.length) return 0;
    else return (stack.num[i]);
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    Stack stack1;
    Stack stack2;
    stack1.length = 0;
    stack2.length = 0;
    for(struct ListNode* tmp = l1;tmp!=NULL;tmp=tmp->next) stack1.num[stack1.length++] = tmp->val;
    for(struct ListNode* tmp = l2;tmp!=NULL;tmp=tmp->next) stack2.num[stack2.length++] = tmp->val;
    int upper_num = 0;
    int result[110];
    int result_length = fmax(stack1.length,stack2.length);
    int add_tmp = 0;
    for(int i=0;i<result_length;i++){
        add_tmp = Getnum(stack1,i) + Getnum(stack2,i) + upper_num;
        upper_num = add_tmp / 10;
        result[i] = add_tmp % 10;
    }
    if(upper_num) result[result_length++] = upper_num;
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* returned = head;
    for(int i=0;i<result_length;i++){
        struct ListNode* to_insert = (struct ListNode*) malloc (sizeof(struct ListNode));
        to_insert->val = result[i];
        returned->next = to_insert;
        returned = returned->next;
    }
    returned->next = NULL;
    return head->next;
}