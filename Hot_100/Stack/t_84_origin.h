#include <malloc.h>
#include <math.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int* height = (int*) malloc (heightsSize*sizeof(int));
    int* index = (int*) malloc (heightsSize*sizeof(int));
    int top = 0;
    int area = 0;
    for(int i=0;i<heightsSize;i++){
        int cur_height = heights[i];
        index[top] = i;
        if(top){
            while(cur_height < height[top-1]){
                top--;
                area = fmax(area,height[top] * (i - index[top]));
                if(!top) break;
            }
        }
        height[top++] = cur_height;
    }
    while(top){
        top--;
        area = fmax(area,height[top] * (heightsSize - index[top]));
    } 
    return area;
}