// pass,both good in time & space
#include <stdint.h>
#include <string.h>
#include <math.h>

# define uint64 uint64_t
int convertToNumber(char c){  // 只用英文字母编码
    if(c >= 'a' && c <= 'z') return c - 'a';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return -1;
}
void enChar(uint64* not_cover,int index){   // 标记某一位存在
    (*not_cover) |= (1ULL << index);
}
void clearChar(uint64* not_cover,int index){   // 标记某一位不存在
    (*not_cover) &= (~((1ULL) << index));
}
char* minWindow(char* s, char* t) {
    int exist[52] = {0};   // 判断是否存在于t串中
    int cur[52] = {0};     // 动态串
    uint64 not_cover = 0;  // 标志每个符号存在状态
    int len_s = strlen(s);
    int len_t = strlen(t);
    for(int i=0;i<len_t;i++){
        int tmp_num = convertToNumber(t[i]);
        if(!exist[tmp_num]){
            exist[tmp_num] = 1;
            enChar(&not_cover,tmp_num);
        }
        cur[tmp_num] ++;
    }
    int left = 0;
    int length = 100010;  
    int begin_index = -1;  // 目标数组起始位
    for(int right=0;right<len_s;right++){
        int right_num = convertToNumber(s[right]);
        if(!exist[right_num]) continue;
        cur[right_num] --;         
        if(cur[right_num] == 0) clearChar(&not_cover,right_num);
        if(not_cover == 0){    // 如果全部数字都已覆盖
            while(true){   // 把left调整到在有效数字上且不会影响整体覆盖正确性
                int left_num = convertToNumber(s[left]);
                if(exist[left_num]){
                    if(cur[left_num] == 0) break;
                    cur[left_num] ++;
                }
                left++;
            }
            if(length > right - left + 1){
                length = right - left + 1;
                begin_index = left;
            }
        }
    }
    if(begin_index == -1) return "\0";
    char* to_return = (char*) malloc((length + 1) * sizeof(char));
    strncpy(to_return,s + begin_index,length); 
    to_return[length] = '\0';
    return to_return;
}