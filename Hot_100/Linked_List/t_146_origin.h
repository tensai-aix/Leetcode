// hash+双向链表
#include "uthash.h"

typedef struct TW_LL{
    struct TW_LL* next;
    struct TW_LL* rear;
    int key;
    int value;
}tw_ll;
typedef struct HASH{
    int key;
    tw_ll* node;
    UT_hash_handle hh;
}Hash;
typedef struct {
    Hash* head;
    tw_ll* lru_list_head;
    tw_ll* lru_list_back;
    int capacity;
    int max_capacity;
} LRUCache;
void MoveToHead(tw_ll* head,tw_ll* to_move){
    to_move->next->rear = to_move->rear;
    to_move->rear->next = to_move->next;
    to_move->next = head->next;
    to_move->rear = head;
    head->next->rear = to_move;
    head->next = to_move;
}
void InsertToHead(tw_ll* head,tw_ll* to_insert){
    head->next->rear = to_insert;
    to_insert->next = head->next;
    to_insert->rear = head;
    head->next = to_insert;
}
tw_ll* GetDeleteNode(tw_ll* back){
    tw_ll* to_return = back->rear;
    to_return->rear->next = back;
    back->rear = to_return->rear;
    return to_return;
}
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*) malloc (sizeof(LRUCache));
    cache->capacity = 0;
    cache->max_capacity = capacity;
    cache->head = NULL;
    cache->lru_list_head = (tw_ll*) malloc (sizeof(tw_ll));
    cache->lru_list_back = (tw_ll*) malloc (sizeof(tw_ll));
    cache->lru_list_head->rear = NULL;
    cache->lru_list_back->next = NULL;
    cache->lru_list_head->next = cache->lru_list_back;
    cache->lru_list_back->rear = cache->lru_list_head;
    return cache;
}
int lRUCacheGet(LRUCache* obj, int key) {
    Hash* to_find;
    HASH_FIND_INT(obj->head,&key,to_find);
    if(!to_find) return -1;
    MoveToHead(obj->lru_list_head,to_find->node);
    return to_find->node->value;   
}
void lRUCachePut(LRUCache* obj, int key, int value) {
    Hash* to_find;
    HASH_FIND_INT(obj->head,&key,to_find);
    // 若存在
    if(to_find){
        to_find->node->value = value;
        MoveToHead(obj->lru_list_head,to_find->node);
        return;
    }
    // 插入
    tw_ll* to_insert_node = (tw_ll*) malloc (sizeof(tw_ll));
    to_insert_node->key = key;
    to_insert_node->value = value;
    InsertToHead(obj->lru_list_head,to_insert_node);
    obj->capacity++;
    Hash* to_insert_hash = (Hash*) malloc (sizeof(Hash));
    to_insert_hash->key = key;
    to_insert_hash->node = to_insert_node;
    HASH_ADD_INT(obj->head,key,to_insert_hash);
    if(obj->capacity <= obj->max_capacity) return;
    // 若超出，删除
    tw_ll* to_delete_node = GetDeleteNode(obj->lru_list_back);
    Hash* to_delete_hash; 
    HASH_FIND_INT(obj->head,&to_delete_node->key,to_delete_hash);
    HASH_DEL(obj->head,to_delete_hash);
    obj->capacity --;
}
void lRUCacheFree(LRUCache* obj) {
    obj->capacity = 0;
    free(obj->head);
    for(tw_ll* tmp = obj->lru_list_head;tmp == obj->lru_list_back;tmp = tmp->next) free(tmp);  
}