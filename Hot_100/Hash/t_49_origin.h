// pass,but too long
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {  
    return (*(char*)a - *(char*)b);  
}  
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    bool check[strsSize];
    char** copy_str = (char**) malloc(strsSize * sizeof(char*));
    for(int i=0;i<strsSize;i++){
        copy_str[i] = (char*) malloc((strlen(strs[i])+1) * sizeof(char));
        strcpy(copy_str[i],strs[i]);
        qsort(copy_str[i], strlen(copy_str[i]), sizeof(char), compare);
        check[i] = false;
    }
    int same[strsSize][101];   // 第i个组里的元素
    int same_number[strsSize];   // 第i个组里的元素个数
    int return_number=0;  // 组数
    for(int i=0;i<strsSize;i++){
        if(check[i]) continue;
        return_number ++;
        same_number[return_number-1] = 1;
        same[return_number-1][0] = i;
        for(int j=i+1;j<strsSize;j++){
            if(check[j]) continue;
            if(strcmp(copy_str[i],copy_str[j]) == 0){
                same_number[return_number-1]++;
                same[return_number-1][same_number[return_number-1]-1] = j;
                check[j] = true;
            }
        }    
    }
    free(copy_str);
    *returnSize = return_number;
    *returnColumnSizes = (int*) malloc (return_number * sizeof(int));
    char*** returned_array = (char*** ) malloc (return_number * sizeof(char** ));
    for(int i=0;i<return_number;i++){
        (*returnColumnSizes)[i] = same_number[i];
        returned_array[i] = (char** ) malloc (same_number[i] * sizeof(char* ));
        for(int j=0;j<same_number[i];j++){
            returned_array[i][j] = (char* ) malloc ((strlen(strs[same[i][j]])+1) * sizeof(char));
            strcpy(returned_array[i][j],strs[same[i][j]]);
        }
    }
    return returned_array;
}