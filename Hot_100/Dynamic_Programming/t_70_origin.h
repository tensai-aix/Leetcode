#include <malloc.h>

int climbStairs(int n) {
    int* method = (int*) malloc ((n + 1) * sizeof(int));
    method[n - 1] = 1;
    method[n] = 1;
    for(int i = n - 2;i >= 0;i--){
        method[i] = method[i + 1] + method[i + 2];
    }
    return method[0];
}