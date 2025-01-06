// 一开始自己想了个解法，没差很多，但是忽略了从（i-1，j）&（i，j-1）移过来的情况
// 而题解赋予了这三种解法更形象的释义，即修改、插入和删除
#include <string.h>

int min(int a,int b,int c){
    return a > b ? b > c ? c : b : a > c ? c : a;
}
int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1 + 1][len2 + 1];
    int i;
    for(i = 0;i <= len1;i++){
        dp[i][0] = i;
    }
    for(i = 0;i <= len2;i++){
        dp[0][i] = i;
    }
    for(i = 1;i <= len1;i++){
        for(int j = 1;j <= len2;j++){
            if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1],dp[i - 1][j],dp[i][j - 1]) + 1;
        }
    }
    return dp[len1][len2];
}