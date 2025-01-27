#include <malloc.h>
#include <string.h>

typedef struct Trie {
    struct Trie* children[26];
    bool isEnd;
} Trie;
Trie* trieCreate() {
    Trie* ret = (Trie*)malloc(sizeof(Trie));
    memset(ret->children, 0, sizeof(ret->children));
    ret->isEnd = false;
    return ret;
}
void trieInsert(Trie* obj, char* word) {
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        int ch = word[i] - 'a';
        if (obj->children[ch] == NULL) {
            obj->children[ch] = trieCreate();
        }
        obj = obj->children[ch];
    }
    obj->isEnd = true;
}
bool trieSearch(Trie* obj, char* word) {
    int n = strlen(word);
    for (int i = 0; i < n; i++) {
        int ch = word[i] - 'a';
        if (obj->children[ch] == NULL) {
            return false;
        }
        obj = obj->children[ch];
    }
    return obj->isEnd;
}
bool trieStartsWith(Trie* obj, char* prefix) {
    int n = strlen(prefix);
    for (int i = 0; i < n; i++) {
        int ch = prefix[i] - 'a';
        if (obj->children[ch] == NULL) {
            return false;
        }
        obj = obj->children[ch];
    }
    return true;
}
void trieFree(Trie* obj) {
    for (int i = 0; i < 26; i++) {
        if (obj->children[i]) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}
