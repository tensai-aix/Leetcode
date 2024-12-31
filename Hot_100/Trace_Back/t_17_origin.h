#include <string.h>
#include <malloc.h>

char symbol[10][4] = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
int length[10] = {0,0,3,3,3,3,3,4,3,4};
char used[4];
int count;
void build(char** ret,char* digits,int level,int size){
    int tmp = digits[level] - '0';
    for(int i = 0;i < length[tmp];i++){
        used[level] = symbol[tmp][i];
        if(level == size - 1) memcpy(ret[count++],used,size * sizeof(char));
        else build(ret,digits,level + 1,size);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    int size = strlen(digits);
    if(size == 0){
        (*returnSize) = 0;
        return NULL;
    }
    (*returnSize) = 1;
    for(int i = 0;i < size;i++){
        (*returnSize) *= length[digits[i] - '0'];
    }
    char** ret = (char**) malloc ((*returnSize) * sizeof(char*));
    for(int i = 0;i < (*returnSize);i++){
        ret[i] = (char*) calloc ((size + 1),sizeof(char));
    }
    count = 0;
    build(ret,digits,0,size);
    return ret;
}