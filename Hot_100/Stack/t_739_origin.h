#include <malloc.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* val = (int*) malloc (temperaturesSize*sizeof(int));
    int* index = (int*) malloc (temperaturesSize*sizeof(int));
    int top = 0;
    int* to_return = (int*) malloc (temperaturesSize*sizeof(int));
    (*returnSize) = temperaturesSize;
    for(int i=0;i<temperaturesSize;i++){
        int cur_temperature = temperatures[i];
        if(top){
            while(cur_temperature > val[top-1]){
                top--;
                to_return[index[top]] = i - index[top];
                if(!top) break;
            }
        }
        val[top] = cur_temperature;
        index[top++] = i;
    }
    while(top) to_return[index[--top]] = 0;
    return to_return;
}