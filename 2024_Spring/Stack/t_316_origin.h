#include <string.h>
#include <malloc.h>

typedef struct Node{
    struct Node* next;
    struct Node* rear;
    char val;
}node;
char* removeDuplicateLetters(char* s) {
    int length = strlen(s);
    node* head = (node*) malloc (sizeof(node));
    int ret_length = 0;
    int num[26] = {0};
    bool exist[26] = {false};
    for(int i = 0;i < length;i++){
        num[s[i] - 'a']++;
    }
    node* now = head;
    node* next;
    node* rear;
    for(int i = 0;i < length;i++){ 
        if(!exist[s[i] - 'a']){
            while(now != head && num[now->val - 'a'] > 0 && s[i] < now->val){
                exist[now->val - 'a'] = false;
                rear = now->rear;
                free(now);
                now = rear;
                ret_length--;
            }
            next = (node*) malloc (sizeof(node));
            next->next = NULL;
            next->val = s[i];
            now->next = next;
            next->rear = now;
            now = next;
            exist[s[i] - 'a'] = true;
            ret_length++;
        }
        num[s[i] - 'a']--;
    }
    char* ret = (char*) malloc ((ret_length + 1) * sizeof(char));
    length = 0;
    for(now = head->next;now;now = now->next){
        ret[length++] = now->val;
    }
    ret[length] = '\0';
    return ret;
}