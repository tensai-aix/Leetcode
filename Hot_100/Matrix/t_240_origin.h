int rowMinSearch(int** matrix,int begin,int end,int target){
    if(end - begin <= 1){
        if(matrix[0][end] <= target) return end;
        if(matrix[0][begin] <= target) return begin;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target < matrix[0][mid]) return rowMinSearch(matrix,begin,mid - 1,target);
    else return rowMinSearch(matrix,mid,end,target);
}
int rowMaxSearch(int** matrix,int col,int begin,int end,int target){
    if(end - begin <= 1){
        if(matrix[col][begin] >= target) return begin;
        if(matrix[col][end] >= target) return end;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target > matrix[col][mid]) return rowMaxSearch(matrix,col,mid + 1,end,target);
    else return rowMaxSearch(matrix,col,begin,mid,target);
}
int colMinSearch(int** matrix,int begin,int end,int target){
    if(end - begin <= 1){
        if(matrix[end][0] <= target) return end;
        if(matrix[begin][0] <= target) return begin;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target < matrix[mid][0]) return colMinSearch(matrix,begin,mid - 1,target);
    else return colMinSearch(matrix,mid,end,target);
}
int colMaxSearch(int** matrix,int row,int begin,int end,int target){
    if(end - begin <= 1){
        if(matrix[begin][row] >= target) return begin;
        if(matrix[end][row] >= target) return end;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target > matrix[mid][row]) return colMaxSearch(matrix,row,mid + 1,end,target);
    else return colMaxSearch(matrix,row,begin,mid,target);
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int r_row = rowMinSearch(matrix,0,matrixColSize[0] - 1,target);
    int r_col = colMinSearch(matrix,0,matrixSize - 1,target);
    int l_row = rowMaxSearch(matrix,matrixSize - 1,0,matrixColSize[0] - 1,target);
    int l_col = colMaxSearch(matrix,matrixColSize[0] - 1,0,matrixSize - 1,target);
    if(r_col == -1 || r_row == -1 || l_col == -1 || l_row == -1) return false;
    for(int i = l_col;i <= r_col;i++){
        for(int j = l_row;j <= r_row;j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}