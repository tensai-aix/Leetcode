// not pass,exceed time
#include <malloc.h>
#include <string.h>

int subarraySum(int* nums, int numsSize, int k) {
    int* store = (int*) malloc (numsSize*sizeof(int));
    int to_return = 0;
    for(int i=0;i<numsSize;i++){
        store[i] = k;
        for(int j = 0;j<=i;j++){
            store[j] -= nums[i];
            if(store[j] == 0) to_return++;
        }
    }
    return to_return;
}
