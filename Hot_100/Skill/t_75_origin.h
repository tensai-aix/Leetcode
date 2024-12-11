#include <math.h>

void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
void sortColors(int* nums, int numsSize) {
    int front = 0;  // 前端第一个非0处
    int rear = numsSize - 1;  // 后端第一个非2处
    int cur_last = 0;  // 遍历1的结尾
    int cur;
    while(true){
        while(nums[front] == 0){
            front++;
            if(front == numsSize) return;
        } 
        while(nums[rear] == 2){
            rear--;
            if(rear == -1) return;
        } 
        for(cur = fmax(cur_last,front);cur<=rear;cur++){
            if(nums[cur] == 0) swap(nums,front,cur);
            else if(nums[cur] == 2) swap(nums,rear,cur);
            if(nums[cur] != 1){
                cur_last = cur;
                break;
            }
        }
        if(cur == rear + 1) break;
    }
}