#include <math.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int n = gridColSize[0];
    int path[gridSize][n];
    for(int i = 0;i < gridSize;i++){
        for(int j = 0;j < n;j++){
            path[i][j] = grid[i][j];
            if(i > 0 && j > 0) path[i][j] += fmin(path[i - 1][j],path[i][j - 1]);
            else if(i > 0) path[i][j] += path[i - 1][j];
            else if(j > 0) path[i][j] += path[i][j - 1];
        }
    }
    return path[gridSize - 1][n - 1];
}