#include <cstddef>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode* collect[100010];
    int number = 0;
    for(struct ListNode* tmp = head;tmp!=NULL;tmp=tmp->next){
        collect[number++] = tmp;
    }
    int left = 0;
    int right = number - 1;
    while(left <= right){
        if(collect[left++]->val != collect[right--]->val) return false;
    }
    return true;
}