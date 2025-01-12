#include <malloc.h>

int* zigzagTraversal(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int row = gridSize;
    int col = gridColSize[0];
    (*returnSize) = (row * col + 1) / 2;
    int* ret = (int*) malloc ((*returnSize) * sizeof(int));
    int count = 0;
    if(row == 1){
        for(int i = 0;i < col;i += 2){
            ret[count++] = grid[0][i];
        }
        return ret;
    }
    if(col == 1){
        for(int i = 0;i < col;i += 2){
            ret[count++] = grid[i][0];
        }
        return ret;
    }
    int i = 0;
    int j = 0;
    int direction = 0;
    bool write = true;
    while(count < (*returnSize)){
        if(write){
            ret[count++] = grid[i][j];
            write = false;
        }
        else write = true;
        switch (direction){
            case 0:{
                j++;
                if(j == col - 1) direction = 1;
                break;
            }
            case 1:{
                i++;
                direction = 2;
                break;
            }
            case 2:{
                j--;
                if(j == 0) direction = 3;
                break;
            }
            case 3:{
                i++;
                direction = 0;
                break;
            }
        }
    }
    return ret;
}