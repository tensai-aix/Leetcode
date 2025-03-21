#include <string.h>
#include <malloc.h>

char* removeKdigits(char* num, int k) {
    int length = strlen(num);
    char stack[length];
    int stack_length = 0;
    for(int pointer = 0;pointer < length;pointer++){
        while(k > 0 && stack_length > 0 && num[pointer] < stack[stack_length - 1]){
            stack_length--;
            k--;
        } 
        stack[stack_length++] = num[pointer];
    }
    int ret_length = stack_length - k;
    int begin = 0;
    while(begin < ret_length && stack[begin] == '0') begin++;
    ret_length -= begin;
    if(ret_length == 0){
        stack[ret_length++] = '0';
        begin = 0;
    } 
    char* ret = (char*) malloc ((ret_length + 1) * sizeof(char));
    memcpy(ret,stack + begin,ret_length * sizeof(char));
    ret[ret_length] = '\0';
    return ret;
}