#include <string.h>
#include <malloc.h>

char* used;
char symbol[10][4] = {{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
int length[10] = {0,0,3,3,3,3,3,4,3,4};
int count;
char** ret;
int size;
void build(char* digits,int level){
    int tmp = digits[level] - '0';
    for(int i = 0;i < length[tmp];i++){
        used[level] = symbol[tmp][i];
        if(level == size - 1){
            memcpy(ret[count],used,size * sizeof(char));
            ret[count][size] = '\0';
            count++;
        }
        else build(digits,level + 1);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    count = 0;
    size = strlen(digits);
    if(size == 0){
        (*returnSize) = 0;
        return NULL;
    }
    (*returnSize) = 1;
    for(int i = 0;i < size;i++){
        (*returnSize) *= length[digits[i] - '0'];
    }
    ret = (char**) malloc ((*returnSize) * sizeof(char*));
    for(int i = 0;i < (*returnSize);i++){
        ret[i] = (char*) malloc ((size + 1) * sizeof(char));
    }
    used = (char*) malloc (size * sizeof(char));
    build(digits,0);
    return ret;
}