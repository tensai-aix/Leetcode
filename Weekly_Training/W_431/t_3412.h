#include <malloc.h>
#include <string.h>

typedef struct node{
    struct node* next;
    int index;
}node;
long long calculateScore(char* s) {
    node* exist[26] = {NULL};
    int length[26] = {0};
    int cur[26] = {0};
    int s_length = strlen(s);
    int now,to_convert;
    node* new_node;
    long long ret = 0;
    for(int i = 0;i < s_length;i++){
        now = s[i] - 'a';
        to_convert = 25 - now;
        if(length[to_convert] == cur[to_convert]){
            length[now]++;
            new_node = (node*) malloc (sizeof(node));
            new_node->index = i;
            if(!exist[now]) exist[now] = new_node;
            else{
                new_node->next = exist[now];
                exist[now] = new_node;
            }
        }
        else{
            cur[to_convert]++;
            ret += i - exist[to_convert]->index;
            exist[to_convert] = exist[to_convert]->next;
        }
    }
    return ret;
}