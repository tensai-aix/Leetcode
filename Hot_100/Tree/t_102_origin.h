#include "define.h"

typedef struct Node{
    int val;
    struct Node* brother;
}Node;
void findMax(struct TreeNode* node,int* ret,int cur){
    if(!node) return;
    cur++;
    if(cur > (*ret)) (*ret) = cur;
    if(node->left) findMax(node->left,ret,cur);
    if(node->right) findMax(node->right,ret,cur);
}
void buildNode(struct TreeNode* root,Node** head_node,int* returnSize,Node** cur_node,int cur,int* grade){
    grade[cur]++;
    Node* tmp = (Node*) malloc (sizeof(Node));
    tmp->val = root->val;
    tmp->brother = NULL;
    if(!head_node[cur]) head_node[cur] = tmp;
    else cur_node[cur]->brother = tmp;
    cur_node[cur] = tmp;
    cur++;
    if(root->left) buildNode(root->left,head_node,returnSize,cur_node,cur,grade);
    if(root->right) buildNode(root->right,head_node,returnSize,cur_node,cur,grade);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        (*returnSize) = 0;
        return NULL;
    }
    int sum = 0;
    findMax(root,&sum,0);
    (*returnSize) = sum;
    Node** head_node = (Node**) calloc (sum,sizeof(Node*));  // 这个要用calloc初始化为NULL，因为在第20行会用到判断！
    Node** cur_node = (Node**) calloc (sum,sizeof(Node*));
    *(returnColumnSizes) = (int*) calloc (sum,sizeof(int));
    buildNode(root,head_node,returnSize,cur_node,0,*returnColumnSizes);
    free(cur_node);
    int** ret = (int**) malloc (sum * sizeof(int*));  
    for(int i=0;i<sum;i++){
        ret[i] = (int*) malloc ((*returnColumnSizes)[i] * sizeof(int));
        Node* tmp = head_node[i];
        int cur = 0;
        while(tmp){
            ret[i][cur++] = tmp->val;
            tmp = tmp->brother;
        }
    }
    return ret;
}