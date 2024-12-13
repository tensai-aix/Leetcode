void clean(char** grid,int i,int j,int row,int col){
    if(i >= row || j >= col || i < 0 || j < 0 || grid[i][j] == '0') return;
    grid[i][j] = '0';
    clean(grid,i + 1,j,row,col);
    clean(grid,i - 1,j,row,col);
    clean(grid,i,j + 1,row,col);
    clean(grid,i,j - 1,row,col);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int row = gridSize;
    int col = gridColSize[0];
    int ret = 0;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(grid[i][j] == '1'){
                ret++;
                clean(grid,i,j,row,col);
            }
        }
    }
    return ret;
}