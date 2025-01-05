#include <string.h>
#include <math.h>

int longestValidParentheses(char* s) {
    int length = strlen(s);
    if(length == 0) return 0;
    bool efficient[length];
    int stack[length];
    int stack_length = 0;
    int i;
    for(i = 0;i < length;i++){
        efficient[i] = false;
        if(s[i] == ')' && stack_length > 0){
            efficient[i] = true;
            efficient[stack[--stack_length]] = true;
        }
        else if(s[i] == '(') stack[stack_length++] = i;
    }
    int tmp_length = 0;
    int ret = 0;
    for(i = 0;i < length;i++){
        if(efficient[i]) tmp_length++;
        else{
            ret = fmax(ret,tmp_length);
            tmp_length = 0;
        }
    }
    return fmax(ret,tmp_length);
}