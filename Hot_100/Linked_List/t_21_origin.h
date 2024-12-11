#include <cstddef>
#include <malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    struct ListNode* returned = head;
    while(true){
        if(list1 == NULL){
            returned->next = list2;
            break;
        } 
        else if(list2 == NULL){
            returned->next = list1;
            break;
        } 
        else{
            if(list1->val <= list2->val){
                returned->next = list1;
                list1 = list1->next;
            }
            else{
                returned->next = list2;
                list2 = list2->next;
            }
            returned = returned->next;
        }     
    }
    return head->next;
}