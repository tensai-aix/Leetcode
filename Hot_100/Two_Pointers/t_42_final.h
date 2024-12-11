// 题解思路：由于在origin，每次找到高于自身的，然后计算面积，但是到达最高点就不行了。
// 但是可以运用对称的思路，右边也从右往左算到最高点，就可以了
#include <math.h>  // 交题解时要注释掉

// 给定左部、右部，计算面积，取二者高度较低值作为基准值，但注意并不是二者之间所有高度都低于基准值
void add_area(int* height,int left,int right,int* area){
    int standard_value = fmin(height[left],height[right]);
    for(int i=left+1;i<right;i++){
        (*area) += fmax(0,standard_value-height[i]);
    }
}
void FindByRightMax(int* height,int* area,int max_index){
    if(max_index<=1) return;  // 只考虑可能有面积的情况，即至少三块
    int left = 0;
    while (left < max_index-1) {
        int left_height = height[left];
        if (left_height == 0) {
            left++;
            continue;
        }
        int right = left + 1;
        while (true) {
            if (right == max_index-1) {  // right到max_value-1了，直接以max_index作为端点计算
                add_area(height,left,max_index,area);
                left = max_index;   
                break; 
            }
            if (height[right] < left_height) {
                right++;
            } 
            else {
                add_area(height,left,right,area);
                left = right;
                break;
            }
        }
    }
}
void FindByLeftMax(int* height,int heightSize,int* area,int max_index){
    if(max_index>=heightSize-2) return;
    int right = heightSize - 1;
    while (right > max_index+1) {
        int right_height = height[right];
        if (right_height == 0) {
            right--;
            continue;
        }
        int left = right - 1;
        while (true) {
            if (left == max_index+1) {
                add_area(height,max_index,right,area);
                right = max_index;   
                break; 
            }
            if (height[left] < right_height) {
                left--;
            } 
            else {
                add_area(height,left,right,area);
                right = left;
                break;
            }
        }
    }
}
int trap(int* height, int heightSize){
    if(heightSize <= 1) return 0;
    int max = 0;
    int index = 0;
    for(int i=0;i<heightSize;i++){
        if(height[i] > max){
            max = height[i];
            index = i;
        } 
    }
    int area=0;
    FindByRightMax(height,&area,index);
    FindByLeftMax(height,heightSize,&area,index);
    return area;
}