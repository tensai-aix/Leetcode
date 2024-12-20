#include <string.h>
#include <malloc.h>

int* partitionLabels(char* s, int* returnSize) {
    int begin[26];
    int end[26];
    for(int i = 0;i < 26;i++){
        begin[i] = -1;
        end[i] = -1;
    }
    int length = strlen(s);
    int tmp;
    for(int i = 0;i < length;i++){
        tmp = s[i] - 'a';
        if(begin[tmp] == -1) begin[tmp] = i;
        end[tmp] = i;
    }
    int* paint = (int*) calloc (length,sizeof(int));
    int same;
    for(int i = 0;i < 26;i++){
        if(begin[i] == -1) continue;
        bool paint_left = paint[begin[i]] != 0;
        bool paint_right = paint[end[i]] != 0;
        if(paint_left && paint_right && paint[begin[i]] != paint[end[i]]){
            same = paint[end[i]];
            tmp = begin[i] - 1;
            while(tmp >= 0 && paint[tmp] == paint[begin[i]]) tmp--;
            while(paint[++tmp] != same) paint[tmp] = same;
        } 
        if(!paint_left && !paint_right){
            for(tmp = begin[i];tmp <= end[i];tmp++){
                paint[tmp] = i + 1;
            }
        }
        if(paint_left && !paint_right){
            same = paint[begin[i]];
            tmp = end[i];
            while(paint[tmp] != same) paint[tmp--] = same;
        }
        if(!paint_left && paint_right){
            same = paint[end[i]];
            tmp = begin[i];
            while(paint[tmp] != same) paint[tmp++] = same;
        }
    }
    int before = 0;
    int cur = 0;
    (*returnSize) = 0;
    int* ret = (int*) malloc (length * sizeof(int));
    while(cur < length){
        if(paint[cur] != paint[before]){
            ret[(*returnSize)++] = cur - before;
            before = cur;
        }
        cur++;
    }
    ret[(*returnSize)++] = cur - before;
    return ret;
}