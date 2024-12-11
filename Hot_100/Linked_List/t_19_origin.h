#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0;
    for(struct ListNode* tmp = head;tmp!=NULL;tmp=tmp->next) count++;
    struct ListNode* to_return = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* var = to_return;
    for(int i=0;i<count - n;i++){
        var->next = head;
        head = head->next;
        var = var->next;
    }
    var->next = head->next;  // 此时head在待删除的节点上
    return to_return->next;
}

// 其他技巧：双指针，右指针比左指针领先n个身位。右指针到头时，删除左指针即可。