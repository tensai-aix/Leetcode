int findcol(int** matrix,int begin,int end,int target){
    if(end - begin <= 1){
        if(target >= matrix[end][0]) return end;
        if(target >= matrix[begin][0]) return begin;
        return -1;
    }
    int mid = (begin + end) / 2;
    if(target >= matrix[mid][0]) return findcol(matrix,mid,end,target);
    else return findcol(matrix,begin,mid - 1,target);
}
bool findRow(int* matrix,int begin,int end,int target){
    if(begin > end) return false;
    int mid = (begin + end) / 2;
    if(matrix[mid] == target) return true;
    if(matrix[mid] < target) return findRow(matrix,mid + 1,end,target);
    return findRow(matrix,begin,mid - 1,target);
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int col = findcol(matrix,0,matrixSize - 1,target);
    if(col < 0) return false;
    return findRow(matrix[col],0,matrixColSize[0] - 1,target);
}