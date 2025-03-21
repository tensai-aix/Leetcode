#include <math.h>

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int row = boardSize;
    int col = boardColSize[0];
    int one[row + 1][col + 1];
    for(int i = 0;i <= col;i++){
        one[0][i] = 0;
    }
    for(int i = 1;i <= row;i++){
        one[i][0] = 0;
    }
    for(int i = 1;i <= row;i++){
        for(int j = 1;j <= col;j++){
            one[i][j] = one[i - 1][j] + one[i][j - 1] - one[i - 1][j - 1] + board[i - 1][j - 1];
        }
    }
    int begin_x,begin_y,end_x,end_y,tmp;
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            begin_x = fmax(i - 1,0);
            end_x = fmin(i + 2,row);
            begin_y = fmax(j - 1,0);
            end_y = fmin(j + 2,col);
            tmp = one[end_x][end_y] + one[begin_x][begin_y] - one[end_x][begin_y] - one[begin_x][end_y] - board[i][j];
            if(board[i][j] && tmp != 2 && tmp != 3) board[i][j] = 0;
            if(!board[i][j] && tmp == 3) board[i][j] = 1;
        }
    }
}