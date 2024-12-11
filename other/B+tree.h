#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/********************************************************************
 * 系列定义
 *******************************************************************/
// 全局变量
struct BPlusTree* leaf;
int recordNum;  // 每个节点记录数
int pointerNum;
int mid;
int side;   // 1表示偏左，2表示偏右

// 数据结构
typedef enum Status{
    Leaf,
    Inode
}Status;
typedef struct BPlusTree{
    int* val; // 多给一位处理溢出情况
    struct BPlusTree** pointer;
    int val_num;
    int pointer_num;
    struct BPlusTree* parent;   // 父索引节点
    int parent_index;   // 在父索引节点中的的位置
    Status status;   // 叶子节点/索引节点
    struct BPlusTree* next;   // 指示叶子节点的下一兄弟
    struct BPlusTree* before; // 指示叶子节点的上一兄弟
}BPlusTree;

// 函数声明
void init(int,int);
void show();
void add(int);
BPlusTree* find(int,bool);
void del(int);

void print(BPlusTree*);
void Inserve(BPlusTree*,int);
BPlusTree* initNode(Status);
void separate(BPlusTree*);
void search(BPlusTree*,int,BPlusTree**,bool);
BPlusTree* combine(BPlusTree*);
bool borrow(BPlusTree*);

/********************************************************************
 * 核心函数
 *******************************************************************/
/**
 * 全局初始化,第一个参数表示每个节点的记录数，第二个参数表示偏左（1）/右（2）分裂
 */
void init(int recordNumber,int sideWay){
    recordNum = recordNumber;
    pointerNum = recordNum + 1;
    if(sideWay == 1){
        mid = (recordNum / 2) + 1;
    }
    else if(sideWay == 2){
        mid = (recordNum + 1) / 2;
    }
    else{
        printf("Error:not invalid side!\n");
        return;
    }
    side = sideWay;
    leaf = initNode(Leaf);
}

/**
 * B+树的搜索操作,第二个参数为是否需要打印搜索路径,返回搜索到的叶子节点
 */
BPlusTree* find(int val,bool needShowWay){
    BPlusTree* root = leaf;
    while(root->parent){
        root = root->parent;
    }
    if(needShowWay){
        printf("search:");
    }
    BPlusTree* ret = (BPlusTree*) malloc (sizeof(BPlusTree));
    search(root,val,&ret,needShowWay);
    return ret;
}

/**
 * B+树的插入操作
 */
void add(int val){
    BPlusTree* cur = find(val,false);
    int to_insert_place;  // 找要插入的节点和位置
    for(to_insert_place = 0;to_insert_place < cur->val_num;to_insert_place++){
        if(val < cur->val[to_insert_place]){
            break;
        }        
    }
    // 插入
    for(int i = cur->val_num;i > to_insert_place;i--){
        cur->val[i] = cur->val[i-1];
    }
    cur->val[to_insert_place] = val;
    cur->val_num++;
    while(cur->val_num > recordNum){
        separate(cur);
        cur = cur->parent;
    }
}

/**
 * B+树的删除操作
 */
void del(int val){
    BPlusTree* cur = find(val,false);
    int to_delete_place;  // 找要删除的节点和位置
    for(to_delete_place = 0;to_delete_place < cur->val_num;to_delete_place++){
        if(val == cur->val[to_delete_place]){
            break;
        }
    }
    if(to_delete_place == cur->val_num){
        printf("Error:no that value!\n");
        return;
    }   
    for(int i = to_delete_place;i < cur->val_num - 1;i++){
        cur->val[i] = cur->val[i + 1];
    }
    cur->val_num--;
    if(cur->parent_index > 0 && to_delete_place == 0){
        cur->parent->val[cur->parent_index - 1] = cur->val[to_delete_place];
    }
    while(cur && cur->val_num < recordNum / 2){
        if(cur->parent == NULL || borrow(cur) == true){
            break;
        }
        cur = combine(cur);
        cur = cur->parent;
    }
}

/**
 * 打印出整棵B+树
 */
void show(){
    BPlusTree* root = leaf;
    while(root->parent){
        root = root->parent;
    }
    printf("\n/**********************************************************************\n");
    Inserve(root,0);
    printf("\n**********************************************************************/\n");
}

/********************************************************************
 * 辅助函数
 *******************************************************************/
/**
 * 函数作用：根据类型初始化节点
 */
BPlusTree* initNode(Status status){
    BPlusTree* new_node = (BPlusTree*) malloc (sizeof(BPlusTree));
    new_node->val_num = 0;
    new_node->pointer_num = 0;
    new_node->status = status;
    new_node->next = NULL;
    new_node->parent = NULL;
    new_node->before = NULL;
    new_node->val = (int*) calloc ((recordNum + 1),sizeof(int));
    new_node->pointer = (BPlusTree**) calloc ((pointerNum + 1),sizeof(BPlusTree*));
    return new_node;
}

/**
 * 函数作用：递归搜索
 */
void search(BPlusTree* root,int val,BPlusTree** ret,bool needShowWay){
    if(root->status == Leaf){
        (*ret) = root;
        for(int i = 0;i < root->val_num;i++){
            if(root->val[i] == val){  // 找到了
                if(needShowWay){
                    printf("%d\nsuccess!\n",val);
                }  
                return;
            } 
        }
        if(needShowWay){
            printf("end\nfail!\n");
        }
    }
    else{
        int i;
        for(i = 0;i < root->val_num;i++){
            if(val < root->val[i]){
                break;
            }
        }
        if(needShowWay){
            if(i < root->val_num){
                printf("(%d left)",root->val[i]);
            }
            else{
                printf("(%d right)",root->val[i - 1]);
            }
            printf(" -> ");
        }
        search(root->pointer[i],val,ret,needShowWay);
    }
}

/**
 * 函数作用：打印节点
 */
void print(BPlusTree* node){
    printf("(");
    for(int i = 0;i < recordNum;i++){
        if(i < node->val_num){
            printf("%d",node->val[i]);
        }
        else{
            printf("null");
        }
        if(i < recordNum - 1){
            printf(", ");
        }
        else{
            printf(")");
        }
    }
}

/**
 * 函数作用：中序遍历打印B+树
 */
void Inserve(BPlusTree* node,int level){
    for(int i = 0;i < level;i++){
        printf("          ");
    }
    printf("node:");
    print(node);
    for(int i = 0;i<pointerNum;i++){
        if(i < node->pointer_num){
            printf("\n");
            Inserve(node->pointer[i],level + 1);
        }     
    }
}

/**
 * 函数作用：分裂节点
 */
void separate(BPlusTree* node){
    BPlusTree* new_node = initNode(node->status);
    int begin_separate_place = mid;
    if(node->status == Inode && side == 2){  // 单独处理索引节点偏右分裂的情况
        begin_separate_place++;
    }
    // 先处理记录
    for(int i = begin_separate_place;i < node->val_num;i++){     
        new_node->val[new_node->val_num++] = node->val[i];
    }
    node->val_num = begin_separate_place;
    if(node->status == Inode){
        node->val_num--;
    }
    // 再处理指针
    if(node->status == Inode){
        for(int i = begin_separate_place;i < node->pointer_num;i++){
            new_node->pointer[new_node->pointer_num] = node->pointer[i];
            node->pointer[i]->parent_index = new_node->pointer_num;
            node->pointer[i]->parent = new_node;
            new_node->pointer_num++;
        }
        node->pointer_num = begin_separate_place;
    }
    // 兄弟之间关联
    if(node->next){
        new_node->next = node->next;
        node->next->before = new_node;
    }
    node->next = new_node;
    new_node->before = node;
    // 向上寻找父节点，没有则创建
    if(node->parent == NULL){
        node->parent = initNode(Inode);
        node->parent_index = 0;
        node->parent->pointer[0] = node;
        node->parent->pointer_num++;
    }
    BPlusTree* node_parent = node->parent; 
    // 分为两部分：自底向上的处理和自顶向下的处理，先是自底向上
    int index = node->parent_index;  
    new_node->parent_index = index + 1; 
    new_node->parent = node_parent;
    // 然后是自顶向下，注意指针和记录分开处理
    for(int i = node_parent->val_num;i >= index + 1;i--){
        node_parent->val[i] = node_parent->val[i - 1];
    }
    if(node->status == Leaf){
        node_parent->val[index] = node->val[begin_separate_place];
    }
    else{
        node_parent->val[index] = node->val[begin_separate_place - 1];
    }
    node_parent->val_num++;
    for(int i = node_parent->pointer_num;i >= index + 2;i--){
        node_parent->pointer[i] = node_parent->pointer[i - 1];
        node_parent->pointer[i]->parent_index++;
    }
    node_parent->pointer[index + 1] = new_node;
    node_parent->pointer_num++;
}

/**
 * 函数作用：寻找并合并节点,返回合并后的节点
 */
BPlusTree* combine(BPlusTree* node){
    BPlusTree* left = NULL;
    BPlusTree* right = NULL;
    if(node->before && node->parent == node->before->parent){
        left = node->before;
        right = node;
    }
    else if(node->next && node->parent == node->next->parent){
        left = node;
        right = node->next;
    }
    if(left == NULL || right == NULL){
        return NULL;
    }
    // 先进行合并
    if(node->status == Inode){
        left->val[left->val_num++] = left->parent->val[left->parent_index];
    }
    for(int i = 0;i < right->val_num;i++){
        left->val[left->val_num++] = right->val[i];
    }
    if(right->next){
        left->next = right->next;
        right->next->before = left;
    }
    if(node->status == Inode){
        for(int i = 0;i < right->pointer_num;i++){
            left->pointer[left->pointer_num] = right->pointer[i];
            left->pointer[left->pointer_num]->parent_index = left->pointer_num;
            left->pointer[left->pointer_num]->parent = left;
            left->pointer_num++;
        }
    }
    free(right);
    // 进行与父结点的交互
    int index = left->parent_index;
    BPlusTree* parent = left->parent;
    for(int i = index;i < parent->val_num - 1;i++){
        parent->val[i] = parent->val[i + 1];
    }
    parent->val_num--;
    // 判断父节点是否仍有效
    if(parent->val_num == 0){
        left->parent = NULL;
        return left;
    }
    for(int i = index + 1;i < parent->pointer_num - 1;i++){
        parent->pointer[i] = parent->pointer[i + 1];
        parent->pointer[i]->parent_index--;
    }
    parent->pointer_num--;
    return left;
}

/**
 * 函数作用：向左右节点借，返回是否借成功
 */
bool borrow(BPlusTree* node){
    if(node->before && node->before->val_num > recordNum / 2 && node->parent == node->before->parent){
        for(int i = node->val_num;i >= 1;i--){
            node->val[i] = node->val[i - 1];
        }
        node->val[0] = node->before->val[--(node->before->val_num)];
        node->val_num++;
        if(node->status == Leaf){
            node->parent->val[node->before->parent_index] = node->val[0];
        }
        else{
            int tmp = node->parent->val[node->before->parent_index];
            node->parent->val[node->before->parent_index] = node->val[0];
            node->val[0] = tmp;
            for(int i = node->pointer_num;i >= 1;i--){
                node->pointer[i] = node->pointer[i - 1];
                node->pointer[i]->parent_index++;
            }
            node->pointer[0] = node->before->pointer[--(node->before->pointer_num)];
            node->pointer[0]->parent_index = 0;
            node->pointer[0]->parent = node;
            node->pointer_num++;
        } 
        return true;
    }
    if(node->next && node->next->val_num > recordNum / 2 && node->parent == node->next->parent){
        node->val[node->val_num++] = node->next->val[0];
        for(int i = 0;i < node->next->val_num - 1;i++){
            node->next->val[i] = node->next->val[i + 1];
        }
        node->next->val_num--;
        if(node->status == Leaf){
            node->parent->val[node->parent_index] = node->next->val[0];
        }
        else{
            int tmp = node->parent->val[node->parent_index];
            node->parent->val[node->parent_index] = node->val[node->val_num - 1];
            node->val[node->val_num - 1] = tmp;
            node->pointer[node->pointer_num++] = node->next->pointer[0];
            for(int i = 0;i < node->next->pointer_num - 1;i++){
                node->next->pointer[i] = node->next->pointer[i + 1];
                node->next->pointer[i]->parent_index--;
            }     
            node->next->pointer_num--;
            node->pointer[node->pointer_num - 1]->parent_index = node->pointer_num - 1;
            node->pointer[node->pointer_num - 1]->parent = node;
        } 
        return true;
    }
    return false;
}