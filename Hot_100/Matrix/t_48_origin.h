void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int level = 0;level < matrixSize / 2;level++){
        for(int i = 0;i < matrixSize - level * 2 - 1;i++){
            int tmp = matrix[level][i + level];
            matrix[level][i + level] = matrix[matrixSize - 1 - level - i][level];
            matrix[matrixSize - 1 - level - i][level] = matrix[matrixSize - 1 - level][matrixSize - 1 - level - i];
            matrix[matrixSize - 1 - level][matrixSize - 1 - level - i] = matrix[i + level][matrixSize - 1 - level];
            matrix[i + level][matrixSize - 1 - level] = tmp;
        }
    }
}