// 思路：有两个哈希表，一个动态，一个静态。初始都按p赋值。然后双指针left、right，right主动，left从动。匹配的过程就是若right在静态哈希表里，
// 则将动态哈希表对应位-1，此时若对应位<0，则移动left直到对应位>=0。若right不在，则移动left到right右边。检查right-left+1，等于p的长度说明匹配成功
// pass,both good
#include <string.h>
#include <malloc.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int ASCII[128] = {0};
    int ASCII_p[128] = {0};
    int to_return[30010];
    (*returnSize) = 0;
    int len_s = strlen(s);
    int len_p = strlen(p);
    if(len_s < len_p) return NULL;
    for(int i=0;i<len_p;i++){
        ASCII_p[p[i]] ++;
        ASCII[p[i]] ++;
    }
    int left = 0;
    int right = 0;
    while(left <= len_s - len_p){
        if(ASCII[s[right]] > 0){
            ASCII_p[s[right]] --;
            if(ASCII_p[s[right]] < 0){
                do{
                    ASCII_p[s[left]] ++;
                    left++;
                }while(ASCII_p[s[right]] < 0);
            }
        }
        else if(ASCII[s[right]] == 0){
            do{
                ASCII_p[s[left]] ++;
                left++;
            }while(left <= right);
        }
        if(right - left + 1 == len_p){
            (*returnSize) ++;
            to_return[(*returnSize)-1] = left;
            ASCII_p[s[left]] ++;
            left++;
        }
        right++;
    }
    int* returned = (int*) malloc ((*returnSize) * sizeof(int));
    memcpy(returned,to_return,(*returnSize)*sizeof(int));
    return returned;
} 