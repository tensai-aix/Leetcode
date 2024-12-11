// 最终优化，用一个数组模拟单调队列。
#include <malloc.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    (*returnSize) = 0;
    int* to_return = (int*) malloc ((numsSize - k + 1)*sizeof(int));
    int queue[numsSize+1];
    int rear = 0;  // 尾部，也是每次的插入点（下一位插入）
    int front = 0;  // 单调队列的虚头部(下一位才是有效的)
    for(int i=0;i<numsSize;i++){
        while(queue[rear] < nums[i] && rear > front) rear--;
        queue[++rear] = nums[i];   // 插入
        if(i < k-1) continue;
        if(i == k-1){
            to_return[(*returnSize)++] = queue[front+1];
            continue;
        }
        if(nums[i-k] == queue[front+1]) front++;  // 弹出
        to_return[(*returnSize)++] = queue[front+1];
    }
    return to_return;
}