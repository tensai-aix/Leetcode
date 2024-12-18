#include <malloc.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int left = 0;
    int right = matrixColSize[0] - 1;
    int up = 0;
    int down = matrixSize - 1;
    (*returnSize) = matrixSize * matrixColSize[0];
    int* ret = (int*) malloc ((*returnSize) * sizeof(int));
    int i = 0;
    int j = 0;
    enum side{t_right,t_down,t_left,t_up};
    enum side Side = t_right;
    int cur = 0;
    while(cur < (*returnSize)){
        ret[cur++] = matrix[i][j];
        if(Side == t_right){
            if(j < right) j++;
            else{
                Side = t_down;
                up++;
                i++;
            }
        }
        else if(Side == t_down){
            if(i < down) i++;
            else{
                Side = t_left;
                right--;
                j--;
            }
        }
        else if(Side == t_left){
            if(j > left) j--;
            else{
                Side = t_up;
                down--;
                i--;
            }
        }
        else{
            if(i > up) i--;
            else{
                Side = t_right;
                left++;
                j++;
            }
        }
    }
    return ret;
}