#include <malloc.h>
#include <ssp/string.h>

#define MAX_SIZE 1430  // 卡特兰数: 1, 1, 2, 5, 14, 42, 132, 429, 1430,借鉴来的
char used[16];
int used_length;
int count;
void build(char** ret,int left,int right,int size){
    if(used_length == 2 * size){
        ret[count] = (char*) calloc ((2 * size + 1),sizeof(char));
        memcpy(ret[count++],used,(2 * size) * sizeof(char));
        return;
    }
    if(left < size){
        used[used_length++] = '(';
        build(ret,left + 1,right,size);
        used_length--;
    }
    if(right < left){
        used[used_length++] = ')';
        build(ret,left,right + 1,size);
        used_length--;
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** ret = (char**) malloc(MAX_SIZE * sizeof(char*));
    used_length = 0;
    count = 0;
    build(ret,0,0,n);
    (*returnSize) = count;
    return ret;
}
