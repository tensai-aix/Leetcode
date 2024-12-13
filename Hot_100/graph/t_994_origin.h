// 思路：模拟传播
#include <malloc.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = gridColSize[0];
    int ret = 0;
    while(true){
        bool no_leave = true;  // 是否还有1
        bool is_same = true;   // 是否有变化
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 1){
                    if(no_leave) no_leave = false;
                    if(i < row - 1 && grid[i + 1][j] == 2) grid[i][j] = 3;
                    else if(i > 0 && grid[i - 1][j] == 2) grid[i][j] = 3;
                    else if(j < col - 1 && grid[i][j + 1] == 2) grid[i][j] = 3;
                    else if(j > 0 && grid[i][j - 1] == 2) grid[i][j] = 3;
                    if(grid[i][j] == 3 && is_same) is_same = false;
                }
            }
        }
        if(no_leave) break;
        if(!no_leave && is_same) return -1;
        ret++;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 3) grid[i][j] = 2;
            }
        }
    }
    return ret;
}