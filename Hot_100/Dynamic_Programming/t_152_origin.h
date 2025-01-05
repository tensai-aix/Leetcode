// perfect in time and space
#include <math.h>

int maxProduct(int* nums, int numsSize) {
    bool is_before = true;
    int mul_before = 0;
    int mul_after = 0;
    int mul_tp = 0;
    int max = INT_MIN;
    int fu_index = -1;
    int tmp;
    for(int i = 0;i <= numsSize;i++){
        if(i == numsSize || nums[i] == 0){
            if(mul_after > 0){
                if(fu_index >= 0){
                    tmp = 1;
                    for(int j = fu_index + 1;j < i;j++){
                        tmp *= nums[j];
                    }
                    if(mul_before > 0 && tmp > mul_before * mul_tp) mul_after = mul_before * mul_tp * mul_after / tmp;
                    if(mul_before == 0 && tmp > mul_tp) mul_after = mul_tp * mul_after / tmp;
                }
                else mul_after = fmax(mul_before,mul_after);
                max = fmax(max,mul_after);
            }
            else if(mul_after == 0) max = mul_before > 0 ? fmax(max,mul_before) : fmax(max,mul_tp);
            else max = mul_before > 0 ? fmax(max,mul_before * mul_tp * mul_after) : fmax(max,mul_tp * mul_after);
            if(i < numsSize){
                is_before = true;
                mul_before = 0;
                mul_after = 0;
                fu_index = -1;
                mul_tp = 0;
                max = fmax(max,0);
            }      
        }
        else{
            if(is_before){
                if(nums [i] > 0){
                    if(mul_before == 0) mul_before = nums[i];
                    else mul_before *= nums[i];
                }
                else{
                    is_before = false;
                    mul_tp = nums[i];
                }
            }
            else{
                if(mul_after == 0) mul_after = nums[i];
                else mul_after *= nums[i];
                if(mul_after < 0) fu_index = i;
            }
        } 
    }
    return max;
}