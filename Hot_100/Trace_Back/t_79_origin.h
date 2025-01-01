#include <string.h>

bool find(char** board,char* word,int i,int j,int row,int col,int index,bool searched[6][6]){
    searched[i][j] = true;
    char to_find = word[index];
    if(to_find == '\0') return true;
    if(i > 0 && board[i - 1][j] == to_find && !searched[i - 1][j] && find(board,word,i - 1,j,row,col,index + 1,searched) == true) return true;  
    if(i < col - 1 && board[i + 1][j] == to_find && !searched[i + 1][j] && find(board,word,i + 1,j,row,col,index + 1,searched) == true) return true;
    if(j > 0 && board[i][j - 1] == to_find && !searched[i][j - 1] && find(board,word,i,j - 1,row,col,index + 1,searched) == true) return true;
    if(j < row - 1 && board[i][j + 1] == to_find && !searched[i][j + 1] && find(board,word,i,j + 1,row,col,index + 1,searched) == true) return true;
    searched[i][j] = false;
    return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int row = boardColSize[0];
    int col = boardSize;
    bool searched[6][6] = {false};
    for(int i = 0;i < col;i++){
        for(int j = 0;j < row;j++){
            if(board[i][j] == word[0] && find(board,word,i,j,row,col,1,searched) == true) return true; 
        }
    }
    return false;
}