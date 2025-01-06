#include <malloc.h>
#include <climits>

void swap(int* heap,int i,int j){
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}
void UP_MAX(int* heap,int heapSize){
    heapSize--;
    int parent = (heapSize - 1) / 2;
    while(parent >= 0 && heap[heapSize] > heap[parent]){
        swap(heap,heapSize,parent);
        heapSize = parent;
        parent = (heapSize - 1) / 2;
    }
}
void UP_MIN(int* heap,int heapSize){
    heapSize--;
    int parent = (heapSize - 1) / 2;
    while(parent >= 0 && heap[heapSize] < heap[parent]){
        swap(heap,heapSize,parent);
        heapSize = parent;
        parent = (heapSize - 1) / 2;
    }
}
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
typedef struct {
    int max_heap[30010];
    int max_heap_size;
    int min_heap[30010];
    int min_heap_size;
} MedianFinder;
MedianFinder* medianFinderCreate() {
    MedianFinder* median = (MedianFinder*) malloc (sizeof(MedianFinder));
    median->max_heap_size = 0;
    median->min_heap_size = 0;
    return median;
}
void medianFinderAddNum(MedianFinder* obj, int num) {
    if((obj->max_heap_size + obj->min_heap_size) % 2 == 0){
        if(obj->min_heap_size == 0) obj->min_heap[obj->min_heap_size++] = num;
        else if(num >= obj->max_heap[0]){
            obj->min_heap[obj->min_heap_size++] = num;
            UP_MIN(obj->min_heap,obj->min_heap_size);
        }
        else{
            obj->min_heap[obj->min_heap_size++] = obj->max_heap[0];
            UP_MIN(obj->min_heap,obj->min_heap_size);
            obj->max_heap[0] = num;
            DOWN_MAX(obj->max_heap,obj->max_heap_size,0);
        }
    }
    else{
        if(obj->max_heap_size == 0){
            if(num > obj->min_heap[0]){
                obj->max_heap[0] = obj->min_heap[0];
                obj->min_heap[0] = num;
                obj->max_heap_size++;
            }
            else obj->max_heap[obj->max_heap_size++] = num;
        }
        else if(num <= obj->min_heap[0]){
            obj->max_heap[obj->max_heap_size++] = num;
            UP_MAX(obj->max_heap,obj->max_heap_size);
        }
        else{
            obj->max_heap[obj->max_heap_size++] = obj->min_heap[0];
            UP_MAX(obj->max_heap,obj->max_heap_size);
            obj->min_heap[0] = num;
            DOWN_MIN(obj->min_heap,obj->min_heap_size,0);
        }
    }
}
double medianFinderFindMedian(MedianFinder* obj) {
    if((obj->max_heap_size + obj->min_heap_size) % 2 == 0){
        return ((double)(obj->max_heap[0] + obj->min_heap[0])) / 2;
    }
    else return obj->min_heap[0];
}
void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
