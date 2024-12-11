// pass,but too complicated
#include <string.h>
# include "uthash.h"

typedef struct t
{
    char key[2];
    int index;
    UT_hash_handle hh;  
}Hash;
void add_hash(char key, int index,Hash** head) { 
    Hash* to_insert = (Hash*)malloc(sizeof(Hash)); 
    to_insert->key[0] = key; 
    to_insert->key[1] = '\0';  
    to_insert->index = index; 
    HASH_ADD_STR(*head, key, to_insert); 
}
Hash* find_hash(char key,Hash* head) { 
    Hash* to_find; 
    char str_key[2] = {key, '\0'}; 
    HASH_FIND_STR(head, str_key, to_find); 
    return to_find;
}
void delete_hash(Hash** head,int index){
    Hash* now;
    Hash* next;
    HASH_ITER(hh,*head,now,next){
        int tmp_index = now->index;
        HASH_DEL(*head,now);
        if(tmp_index == index) break;
    }
}
int lengthOfLongestSubstring(char* s) {
    Hash* head=NULL;
    int returned=0;
    int length = strlen(s);
    if(length <= 1) return length;
    add_hash(s[0],0,&head);
    int left = 0;
    int right = left + 1;
    while(left<=length-2){
        Hash* right_same_hash;
        while(true){
            right_same_hash = find_hash(s[right],head);
            if(right_same_hash) break;
            add_hash(s[right],right,&head);
            right++;
            if (right == length) break;
        }
        if(right_same_hash){
            int new_returned = right - left;
            if(new_returned > returned) returned = new_returned;
            delete_hash(&head,right_same_hash->index);
            add_hash(s[right],right,&head);
            left = right_same_hash->index + 1;
            right++;
        }
        if(right == length){
            int new_returned = right - left;
            if(new_returned > returned) returned = new_returned;
            left = length;
            break;
        }
    }
    return returned;
}