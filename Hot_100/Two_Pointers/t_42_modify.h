// can't pass,beacuse peek is not enough
#include <math.h>

void add_area(int* height,int left,int right,int* area){
    int max_value = fmin(height[left],height[right]);
    for(int i=left+1;i<right;i++){
        (*area) += fmax(0,max_value-height[i]);
    }
}
int trap(int* height, int heightSize){
    if(heightSize <= 1) return 0;
    int area=0;
    int index = 0;
    for(int forward=index+1;;forward++){
        if(forward == heightSize - 1){
            add_area(height,index,forward,&area);
            index = heightSize;
            break;
        }
        if(height[forward] > height[forward-1] && height[forward] > height[forward+1]){
            add_area(height,index,forward,&area);
            index = forward;
        }
    }
    return area;
}