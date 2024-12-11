// 单调队列,用双向链表和队列实现
#include <malloc.h>

typedef struct NODE{
    int value;
    struct NODE* next; 
    struct NODE* prev;
}Node; 
typedef struct{
    Node* front; 
    Node* rear;
}Queue;
void init(Queue* queue){
    queue->front = (Node*) malloc (sizeof(Node));
    queue->rear = (Node*) malloc (sizeof(Node));
    queue->front->next = queue->rear;
    queue->rear->prev = queue->front;
}
void add(Queue* queue,int to_insert_num){
    Node* tmp;
    for(tmp=queue->rear->prev;tmp != queue->front;tmp = tmp->prev){
        if(tmp->value >= to_insert_num) break;
    }
    Node* to_insert_node = (Node*) malloc (sizeof(Node));
    to_insert_node->value = to_insert_num;
    tmp->next = to_insert_node;
    to_insert_node->prev = tmp;
    to_insert_node->next = queue->rear;
    queue->rear->prev = to_insert_node;
}
void pop(Queue* queue){
    queue->front->next->next->prev = queue->front;
    queue->front->next = queue->front->next->next;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    (*returnSize) = 0;
    int* to_return = (int*) malloc ((numsSize - k + 1)*sizeof(int));
    Queue* queue = (Queue*) malloc (sizeof(Queue));
    init(queue);
    for(int i=0;i<numsSize;i++){
        add(queue,nums[i]);
        if(i < k-1) continue;
        if(i == k-1){
            to_return[(*returnSize)++] = queue->front->next->value;
            continue;
        }
        if(nums[i-k] == queue->front->next->value){
            pop(queue);
        }
        to_return[(*returnSize)++] = queue->front->next->value;
    }
    return to_return;
}