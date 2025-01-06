#include <malloc.h>
/********************************************************************
 * 系列定义
 *******************************************************************/
// 宏
#define length 100

// 全局变量
bool isMax_heap;  // 表示是最大堆还是最小堆，true表示最大堆,false表示最小堆
int* heap;  // 堆
int heap_size;

// 函数声明
void init(int heapSize,bool is_max_heap);
void add(int val);
void del();
void adjust(int* nums,int numsSize,bool is_max_heap);
void addNUM(int val,int* nums,int numsSize,bool is_max_heap);
void delTop(int* nums,int numsSize,bool is_max_heap);

void UP_MAX(int* heap,int index);
void UP_MIN(int* heap,int index);
void DOWN_MAX(int* heap,int heap_size,int index);
void DOWN_MIN(int* heap,int heap_size,int index);

/********************************************************************
 * 核心函数
 *******************************************************************/
/**
 * 初始化堆，传入参数为大小，如果不想设定则传入0即可，此时默认长度100。第二个参数表示是否为最大堆（否则为最小堆）
 */
void init(int heapSize,bool is_max_heap){
    if(heapSize > 0){
        heap = (int*) malloc (heapSize * sizeof(int));
    }
    else{
        heap = (int*) malloc (length * sizeof(int));
    }
    heap_size = 0;
    isMax_heap = is_max_heap;
}

/**
 * 堆中插入元素
 */
void add(int val){
    heap[heap_size++] = val;
    if(isMax_heap){
        UP_MAX(heap,heap_size - 1);
    }
    else{
        UP_MIN(heap,heap_size - 1);
    }
}

/**
 * 删除堆顶元素
 */ 
void del(){
    heap[0] = heap[--heap_size];
    if(isMax_heap){
        DOWN_MAX(heap,heap_size,0);
    }
    else{
        DOWN_MIN(heap,heap_size,0);
    }
}

/**
 * 调整数组使其满足堆的结构
 */
void adjust(int* nums,int numsSize,bool is_max_heap){
    for(int i = numsSize / 2 - 1;i >= 0;i--){
        if(is_max_heap){
            DOWN_MAX(nums,numsSize,i);
        }
        else{
            DOWN_MIN(nums,numsSize,i);
        }
    }
}

/**
 * 往已有的堆里插入元素
 */
void addNUM(int val,int* nums,int numsSize,bool is_max_heap){
    nums[numsSize++] = val;
    if(is_max_heap){
        UP_MAX(nums,numsSize - 1);
    }
    else{
        UP_MIN(nums,numsSize - 1);
    }
}

/**
 * 删除已有堆的堆顶元素
 */ 
void delTop(int* nums,int numsSize,bool is_max_heap){
    nums[0] = nums[--numsSize];
    if(is_max_heap){
        DOWN_MAX(nums,numsSize,0);
    }
    else{
        DOWN_MIN(nums,numsSize,0);
    }
}

/********************************************************************
 * 辅助函数
 *******************************************************************/
/**
 * 交换函数
 */
void swap(int* heap,int i,int j){
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

/**
 * 最大堆的上浮
 */
void UP_MAX(int* heap,int heapSize){
    heapSize--;
    int parent = (heapSize - 1) / 2;
    while(parent >= 0 && heap[heapSize] > heap[parent]){
        swap(heap,heapSize,parent);
        heapSize = parent;
        parent = (heapSize - 1) / 2;
    }
}

/**
 * 最小堆的上浮
 */
void UP_MIN(int* heap,int heapSize){
    heapSize--;
    int parent = (heapSize - 1) / 2;
    while(parent >= 0 && heap[heapSize] < heap[parent]){
        swap(heap,heapSize,parent);
        heapSize = parent;
        parent = (heapSize - 1) / 2;
    }
}

/**
 * 最大堆的下沉
 */
void DOWN_MAX(int* heap,int heapSize,int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if(left < heapSize && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < heapSize && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != index){
        swap(heap,index,largest);
        DOWN_MAX(heap,heapSize,largest);
    }
}

/**
 * 最小堆的下沉
 */
void DOWN_MIN(int* heap,int heapSize,int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largest = index;
    if(left < heapSize && heap[left] < heap[largest]){
        largest = left;
    }
    if(right < heapSize && heap[right] < heap[largest]){
        largest = right;
    }
    if(largest != index){
        swap(heap,index,largest);
        DOWN_MIN(heap,heapSize,largest);
    }
}