#include <math.h>

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {  
        tmp = b;  
        b = a % b;
        a = tmp;   
    }  
    return a; 
}
int maxLength(int* nums, int numsSize) {
    int huzhi[numsSize];
    int i,j;
    for(i = 0;i < numsSize;i++){
        huzhi[i] = 0;
        if(nums[i] != 1){
            for(j = i + 1;j < numsSize;j++){
                if(gcd(nums[i],nums[j]) != 1) break;
            }
            if(j != numsSize) huzhi[i] = j;
        }
    }
    int tmp_length = 0;
    int ret = 2;
    int this_end = numsSize;
    int next_begin;
    for(i = 0;i < numsSize;i++,tmp_length++){
        if(i == this_end){
            ret = fmax(ret,tmp_length);
            tmp_length = 0;
            this_end = numsSize;
            i = next_begin;
        }
        if(huzhi[i] && huzhi[i] < this_end){
            this_end = fmin(this_end,huzhi[i]);
            next_begin = i + 1;
        } 
    }
    return fmax(ret,tmp_length);
} 