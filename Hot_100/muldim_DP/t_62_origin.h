int uniquePaths(int m, int n) {
    int path[m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            path[i][j] = 0;
        }
    }
    path[0][0] = 1;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(i < m - 1) path[i + 1][j] += path[i][j];
            if(j < n - 1) path[i][j + 1] += path[i][j];
        }
    }
    return path[m - 1][n - 1];
}