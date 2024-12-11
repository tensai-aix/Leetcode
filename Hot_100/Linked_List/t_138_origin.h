#include <malloc.h>
#include "uthash.h"
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

typedef struct HASH{
    struct Node* node;
    int index;
    UT_hash_handle hh;
}Hash;
struct Node* copyRandomList(struct Node* head) {
    int length = 0;
    Hash* head_table = NULL;
    for(struct Node* tmp = head;tmp!=NULL;tmp=tmp->next){      // 将节点加入哈希表
        Hash* to_insert_hash = (Hash*) malloc (sizeof(Hash));
        to_insert_hash->index = length;
        to_insert_hash->node = tmp;
        HASH_ADD_PTR(head_table,node,to_insert_hash);
        length++;
    }
    int* index = (int*) malloc (length*sizeof(int));  
    struct Node** collect = (struct Node**) malloc ((length+1)*sizeof(struct Node*));  // 留一个给NULL
    int i = 0;
    for(struct Node* tmp = head;tmp!=NULL;tmp=tmp->next){    // 新建节点并计算节点random的偏移量
        Hash* get;
        HASH_FIND_PTR(head_table,&(tmp->random),get);
        if(!get) index[i] = length - i;
        else index[i] = get->index - i; 
        struct Node* to_insert_node = (struct Node*) malloc (sizeof(struct Node));
        to_insert_node->val = tmp->val;
        collect[i] = to_insert_node;         
        i++;
    }
    collect[length] = NULL;
    struct Node* to_return = (struct Node*) malloc (sizeof(struct Node));
    struct Node* cur = to_return;
    for(i = 0;i<length;i++){   // 根据新建节点构建链表
        collect[i]->random = collect[i+index[i]];
        cur->next = collect[i];
        cur = cur->next;
    }
    cur->next = NULL;
    return to_return->next;
}

// 有一个很聪明的做法，新构建链表，每个节点后面接一个这个节点的复制（称为源节点和复制节点）。遍历源节点，设置复制节点的random就等于源节点的random的复制节点，然后复制节点即为所求。太聪明了！