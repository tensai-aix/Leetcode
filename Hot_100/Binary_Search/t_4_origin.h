#include <stdlib.h>
 
int find(int* nums1,int n1_begin,int n1_end,int* nums2,int n2_begin,int n2_end,int left){
    if(n1_begin > n1_end) return nums2[n2_begin + left - 1];
    if(n2_begin > n2_end) return nums1[n1_begin + left - 1];
    if(left == 1){
        if(nums1[n1_begin] < nums2[n2_begin]) return nums1[n1_begin];
        else return nums2[n2_begin];
    }
    int mid1 = (n1_begin + n1_end) / 2;
    int mid2 = (n2_begin + n2_end) / 2;
    int half_length1 = mid1 - n1_begin + 1;
    int half_length2 = mid2 - n2_begin + 1;
    if(left >= (half_length1 + half_length2)){
        if(nums1[mid1] < nums2[mid2]) return find(nums1,mid1 + 1,n1_end,nums2,n2_begin,n2_end,left - (mid1 - n1_begin + 1));
        else return find(nums1,n1_begin,n1_end,nums2,mid2 + 1,n2_end,left - (mid2 - n2_begin + 1));
    }
    else if(left <= half_length1 && left <= half_length2)  return find(nums1,n1_begin,mid1,nums2,n2_begin,mid2,left);
    else if(left <= half_length1 && left > half_length2)  return find(nums1,n1_begin,mid1,nums2,n2_begin,n2_end,left);
    else if(left > half_length1 && left <= half_length2)  return find(nums1,n1_begin,n1_end,nums2,n2_begin,mid2,left);
    else{
        if(nums1[mid1] < nums2[mid2]) return find(nums1,n1_begin,n1_end,nums2,n2_begin,mid2 - 1,left);
        else return find(nums1,n1_begin,mid1 - 1,nums2,n2_begin,n2_end,left);
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if(total % 2 == 1){
        return find(nums1,0,nums1Size - 1,nums2,0,nums2Size - 1,(total + 1) / 2);
    }
    else{
        return ((double)(find(nums1,0,nums1Size - 1,nums2,0,nums2Size - 1,total / 2)) + (double)find(nums1,0,nums1Size - 1,nums2,0,nums2Size - 1,total / 2 + 1)) / 2;
    }
}