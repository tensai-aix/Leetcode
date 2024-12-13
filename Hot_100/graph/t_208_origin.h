// fail,因为我想着一层放一个节点，但实际应该一个节点连另外一个节点，然后设置标志位判断是否为完整单词
#include <cstddef>
#include <stdlib.h>
#include <string.h>

#define wordNum 26
typedef struct node{
    char* word;
    struct node* next;
}node;
typedef struct Trie{
    bool exist[wordNum];
    struct Trie* next;
    node* head;
} Trie;
Trie* trieCreate() {
    Trie* ret = (Trie*) malloc (sizeof(Trie));
    for(int i = 0;i < wordNum;i++){
        ret->exist[i] = false;
    }
    ret->next = NULL;
    ret->head = NULL;
    return ret;
}
void trieInsert(Trie* obj, char* word) {
    int length = strlen(word);
    int i;
    for(i = 0;i < length - 1;i++){
        obj->exist[word[i] - 'a'] = true;
        if(!obj->next) obj->next = trieCreate();
        obj = obj->next;
    }
    obj->exist[word[i] - 'a'] = true;
    if(!obj-> head){
        obj->head = (node*) malloc (sizeof(node));
        obj->head->word = (char*) malloc ((length + 1) * sizeof(char));
        obj->head->next = NULL;
        strcpy(obj->head->word,word);
    }
    else{
        node* tmp = obj->head;
        while(tmp->next) tmp = tmp->next;
        tmp->next = (node*) malloc (sizeof(node));
        tmp->next->word = (char*) malloc ((length + 1) * sizeof(char));
        tmp->next->next = NULL;
        strcpy(tmp->next->word,word);
    }
}
bool trieSearch(Trie* obj, char* word) {
    int length = strlen(word);
    int i;
    for(i = 0;i < length - 1;i++){
        if(!obj->exist[word[i] - 'a'] || !obj->next) return false;
        obj = obj->next;
    }
    if(!obj->exist[word[i] - 'a']) return false;
    if(!obj->head) return false;
    for(node* tmp = obj->head;tmp;tmp = tmp->next){
        if(strcmp(tmp->word,word) == 0) return true;
    }
    return false;
}
bool trieStartsWith(Trie* obj, char* prefix) {
    int length = strlen(prefix);
    int i;
    for(i = 0;i < length - 1;i++){
        if(!obj->exist[prefix[i] - 'a'] || !obj->next) return false;
        obj = obj->next;
    }
    if(!obj->exist[prefix[i] - 'a']) return false;
    return true;
}
void trieFree(Trie* obj) {
    free(obj);
}