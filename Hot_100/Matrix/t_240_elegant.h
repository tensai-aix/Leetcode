bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize, n = matrixColSize[0];
    int i = 0, j = n - 1; // 从右上角开始
    while (i < m && j >= 0) { // 还有剩余元素
        if (matrix[i][j] == target) {
            return true; // 找到 target
        }
        if (matrix[i][j] < target) {
            i++; // 这一行剩余元素全部小于 target，排除
        } else {
            j--; // 这一列剩余元素全部大于 target，排除
        }
    }
    return false;
}