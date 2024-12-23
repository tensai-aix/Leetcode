void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    bool isRow = false,isCol = false;
    for(int i = 0;i < matrixSize;i++){
        if(matrix[i][0] == 0){
            isCol = true;
            break;
        }
    }
    for(int j = 0;j < matrixColSize[0];j++){
        if(matrix[0][j] == 0){
            isRow = true;
            break;
        }
    }
    for(int i = 0;i < matrixSize;i++){
        for(int j = 0;j < matrixColSize[0];j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1;i < matrixSize;i++){
        if(matrix[i][0] == 0) {
            for(int j = 1;j < matrixColSize[0];j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 1;j < matrixColSize[0];j++){
        if(matrix[0][j] == 0) {
            for(int i = 1;i < matrixSize;i++){
                matrix[i][j] = 0;
            }
        }
    }
    if(isRow){
        for(int j = 0;j < matrixColSize[0];j++){
            matrix[0][j] = 0;
        }
    }
    if(isCol){
        for(int i = 0;i < matrixSize;i++){
            matrix[i][0] = 0;
        }
    }
}