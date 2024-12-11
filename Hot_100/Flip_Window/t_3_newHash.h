#include <string.h>

int lengthOfLongestSubstring(char * s){
    int hash[128] = {0};    // 模拟哈希表
    int max = 0;    // 最大值
    for(int i = 0, j = 0; i < strlen(s); i++){
        hash[s[i]]++;
        while(hash[s[i]] > 1) hash[s[j++]]--;
        max = max < (i-j+1)?(i-j+1):max;
    }
    return max;
}

// 太优雅了！用ASCII模拟哈希表，然后我的insert操作就是他直接哈希值加一，删除操作就是哈希值减一，直到减到不出现重复为止。
// 其实我的实现更简单，少算一些，但奈何他的太简练了。