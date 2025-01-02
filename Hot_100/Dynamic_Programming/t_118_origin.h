#include <malloc.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ret = (int**) malloc (numRows * sizeof(int*));
    (*returnSize) = numRows;
    (*returnColumnSizes) = (int*) malloc (numRows * sizeof(int));
    for(int i = 0;i < numRows;i++){
        ret[i] = (int*) malloc ((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = 1;
        ret[i][i] = 1;
        for(int j = 1;j < i;j++){
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}