#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void reshape(struct ListNode** cur,int qsize,int index,int length){
    if(length - index <= qsize) return;
    struct ListNode* right = (*cur);
    struct ListNode* left = (*cur);
    struct ListNode* build = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* re_shape = build;
    int l_go = 0;
    int r_go = 0;
    for(int i=0;i<qsize;i++){
        right = right->next;
    }
    while(true){
        if(l_go == qsize){
            build->next = right;
            break;
        } 
        else if(r_go ==  qsize || right == NULL){
            build->next = left;
            break;
        } 
        else{
            if(left->val <= right->val){
                build->next = left;
                left = left->next;
                l_go++;
            }
            else{
                build->next = right;
                right = right->next;
                r_go++;
            }
            build = build->next;
        }
    }
    (*cur) = re_shape->next;
}
struct ListNode* sortList(struct ListNode* head) {
    int length = 0;
    for(struct ListNode* tmp = head;tmp!=NULL;tmp=tmp->next) length++;
    int qsize = 1;
    while(qsize < length){
        struct ListNode* cur = head;
        struct ListNode* next_begin = cur;  // 下一个操作的起始位
        struct ListNode* before_last = (struct ListNode*) malloc (sizeof(struct ListNode)); // 上一个操作的末位
        for(int index = 0;index < length;index+=(qsize*2)){
            for(int i=0;i<(qsize*2);i++){  // 先找到下一个操作的起始位，这是未被污染的
                if(next_begin) next_begin = next_begin->next;
            } 
            reshape(&cur,qsize,index,length);  // 重塑本次操作的起始位及内部顺序
            before_last->next = cur;  // 上个操作的末位连接本次操作的起始位
            if(index == 0) head = cur;   // 保存总的起始位到head
            for(int i=0;i<(qsize*2)-1;i++){
                if(index + i == length - 1) break;
                cur = cur->next;     // 找到本次操作的末位
            } 
            before_last = cur;
            cur->next = next_begin;
            cur = next_begin;
        }
        qsize*=2;
    }
    return head;
}