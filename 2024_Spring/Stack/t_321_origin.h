#include <malloc.h>

void swap(int* nums,int i,int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    int top = 0;
    (*returnSize) = k;
    int* ret = (int*) malloc ((nums1Size + nums2Size) * sizeof(int));
    int pointer1 = 0;
    int pointer2 = 0;
    int to_insert;
    k = nums1Size + nums2Size - k;
    int from[nums1Size + nums2Size];
    int tmp_from;
    while(pointer1 < nums1Size || pointer2 < nums2Size){
        if(pointer1 == nums1Size){
            to_insert = nums2[pointer2++];
            tmp_from = 2;
        } 
        else if(pointer2 == nums2Size){
            to_insert = nums1[pointer1++];
            tmp_from = 1;
        } 
        else{
            if(nums1[pointer1] > nums2[pointer2]){
                to_insert = nums1[pointer1++];
                tmp_from = 1;
            }
            else{
                to_insert = nums2[pointer2++];
                tmp_from = 2;
            }
        } 
        while(k > 0 && top > 0 && to_insert > ret[top - 1]){
            if(tmp_from == from[top - 1]){
                k--;
            }
            else{
                if(tmp_from == 1){
                    pointer2--;
                    // what's this?
                    swap(ret,pointer2,0);
                }
                else{
                    pointer1--;
                }
            }
            top--;  
        }
        ret[top] = to_insert;
        from[top++] = tmp_from;
    }
    return ret;
}