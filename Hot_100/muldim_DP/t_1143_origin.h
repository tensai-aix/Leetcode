// DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise
#include <string.h>
#include <math.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int len_1 = strlen(text1);
    int len_2 = strlen(text2);
    int dp[len_1][len_2];
    bool flag = false;
    for(int i = 0;i < len_2;i++){
        if(text2[i] == text1[0]) flag = true;
        if(flag) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    flag = false;
    for(int i = 0;i < len_1;i++){
        if(text1[i] == text2[0]) flag = true;
        if(flag) dp[i][0] = 1;
        else dp[i][0] = 0;
    }
    for(int i = 1;i < len_1;i++){
        for(int j = 1;j < len_2;j++){
            if(text1[i] == text2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = fmax(dp[i - 1][j],dp[i][j - 1]);
        }
    }
    return dp[len_1 - 1][len_2 - 1];
}