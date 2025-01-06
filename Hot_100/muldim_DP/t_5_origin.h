#include <string.h>
#include <math.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    int i,j,k;
    int tmp_length;
    int ret_length = 1;
    int ret_index = 0;
    for(i = 0;i < length;i++){
        if(i > 0 && s[i] == s[i - 1]){
            j = i + 1;
            k = i - 2;
            tmp_length = 2;
            while(k >= 0 && j < length && s[k] == s[j]){
                j++;
                k--;
                tmp_length += 2;
            }
            if(tmp_length > ret_length){
                ret_index = k + 1;
                ret_length = tmp_length;
            }
        }
        if(i > 1 && s[i] == s[i - 2]){
            j = i + 1;
            k = i - 3;
            tmp_length = 3;
            while(k >= 0 && j < length && s[k] == s[j]){
                j++;
                k--;
                tmp_length += 2;
            }
            if(tmp_length > ret_length){
                ret_index = k + 1;
                ret_length = tmp_length;
            }
        }
    }
    char* ret = (char*) calloc ((ret_length + 1),sizeof(char));
    memcpy(ret,s + ret_index,(ret_length) * sizeof(char));
    return ret;
}