#include <malloc.h>
#include <ssp/string.h>
#include <math.h>

int count;
int store[9];  
int store_length;
char points[10] = {"........."};
int square[9][9] = {0};
char*** ret;
int size;
void paint(int i,int j,int num){
    for(int tmp = 0;tmp < size;tmp++){
        square[i][tmp] += num;
        square[tmp][j] += num;
    }
    int tmp_i = fmax(i - j,0);
    int tmp_j = fmax(j - i,0);
    while(tmp_i < size && tmp_j < size){
        square[tmp_i][tmp_j] += num;
        tmp_i++;
        tmp_j++;
    }
    int tmp_min = fmin(size - 1 - i,j);
    tmp_i = i + tmp_min;
    tmp_j = j - tmp_min;
    while(tmp_i >= 0 && tmp_j < size){
        square[tmp_i][tmp_j] += num;
        tmp_i--;
        tmp_j++;
    }
}
void build(){
    if(store_length == size){
        ret[count] = (char**) malloc (size * sizeof(char*));
        for(int i = 0;i < size;i++){
            ret[count][i] = (char*) malloc ((size + 1) * sizeof(char));
            memcpy(ret[count][i],points,size * sizeof(char));
            ret[count][i][store[i]] = 'Q';
            ret[count][i][size] = '\0';
        }
        count++;
        return;
    }
    for(int i = 0;i < size;i++){
        if(square[store_length][i] == 0){
            paint(store_length,i,1);
            store[store_length++] = i;
            build();
            store_length--;
            paint(store_length,i,-1);
        }
    }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    ret = (char***) malloc (500 * sizeof(char**));
    count = 0;
    store_length = 0;
    size = n;
    build();
    (*returnColumnSizes) = (int*) malloc (count * sizeof(int));
    for(int i = 0;i < count;i++) (*returnColumnSizes)[i] = n;
    (*returnSize) = count;
    return ret;
}