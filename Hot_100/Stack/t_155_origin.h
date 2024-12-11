#include <malloc.h>
#include <cstddef>

typedef struct Node{
    struct Node* next;
    int val;
}Node;
typedef struct {
    Node* head;
    int val[30010];
    int top;
} MinStack;
MinStack* minStackCreate() {
    MinStack* stack = (MinStack*) malloc (sizeof(MinStack));
    stack->head = (Node*) malloc (sizeof(Node));
    stack->head->next = NULL;
    stack->top = 0;
    return stack;
}
void minStackPush(MinStack* obj, int val) {
    obj->val[obj->top++] = val;
    Node* node = (Node*) malloc (sizeof(Node));
    node->val = val;
    node->next = NULL;
    if(!obj->head->next){
        obj->head->next = node;
        return;
    } 
    Node* tmp;
    for(tmp=obj->head;tmp->next;tmp = tmp->next){
        if(val < tmp->next->val){
            node->next = tmp->next;
            tmp->next = node;
            return;
        }   
    }
    tmp->next = node;
}
void minStackPop(MinStack* obj) {
    obj->top--;
    int val = obj->val[obj->top];
    for(Node* tmp=obj->head;tmp->next;tmp = tmp->next){
        if(val == tmp->next->val){
            tmp->next = tmp->next->next;
            return;
        }
    }
}
int minStackTop(MinStack* obj) {
    return obj->val[obj->top-1];
}
int minStackGetMin(MinStack* obj) {
    return obj->head->next->val;
}
void minStackFree(MinStack* obj) {
    obj->top = 0;
    free(obj->head);
}

// 还看到一个很巧的思路，每个元素进栈时，保存下当前栈中的最小值。