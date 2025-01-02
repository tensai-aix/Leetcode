#include <malloc.h>
#include <ssp/string.h>

char stack[16];
int stack_length;
int sep_index[17] = {0};
int sep_length;
int count;
void build(char*** ret,char* s,int index,int* retColSize){
    if(s[index] == '\0'){
        if(stack_length == 0){
            int tmp_length;
            ret[count] = (char**) malloc (sep_length * sizeof(char*));
            retColSize[count] = sep_length;
            for(int i = 0;i < sep_length;i++){
                tmp_length = sep_index[i + 1] - sep_index[i];
                ret[count][i] = (char*) malloc ((tmp_length + 1) * sizeof(char));
                memcpy(ret[count][i],s + sep_index[i],tmp_length * sizeof(char));
                ret[count][i][tmp_length] = '\0';
            }
            count++;
        }
        return;
    }
    stack[stack_length++] = s[index];
    bool isCircle = true;  
    for (int i = 0, j = stack_length - 1; i < j; i++, j--) {  
        if (stack[i] != stack[j]) {  
            isCircle = false;  
            break;  
        }  
    } 
    if(isCircle){
        char* store = (char*) malloc (stack_length * sizeof(char));
        int store_length = stack_length;
        memcpy(store,stack,stack_length * sizeof(char));
        sep_index[++sep_length] = index + 1;
        stack_length = 0;
        build(ret,s,index + 1,retColSize);
        sep_length--;
        memcpy(stack,store,store_length * sizeof(char));
        stack_length = store_length;
        free(store);
    }  
    build(ret,s,index + 1,retColSize);
    stack_length--;
}
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    count = 0;
    stack_length = 0;
    sep_length = 0;
    char*** ret = (char***) malloc (50000 * sizeof(char**));
    (*returnColumnSizes) = (int*) malloc (50000 * sizeof(int));
    build(ret,s,0,*returnColumnSizes);
    (*returnSize) = count;
    return ret;
}