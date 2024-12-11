#include "define.h"

#define max 110
void findMax(struct TreeNode* node,int* ret,int cur){
    if(!node) return;
    cur++;
    if(cur > (*ret)) (*ret) = cur;
    if(node->left) findMax(node->left,ret,cur);
    if(node->right) findMax(node->right,ret,cur);
}
void build(struct TreeNode* node,int* ret,int grade){
    if(ret[grade] == max) ret[grade] = node->val;
    if(node->right) build(node->right,ret,grade+1);
    if(node->left) build(node->left,ret,grade+1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(!root){
        (*returnSize) = 0;
        return NULL;
    }
    int length = 0;
    findMax(root,&length,0);
    (*returnSize) = length;
    int* ret = (int*) calloc (length,sizeof(int));
    for(int i=0;i<length;i++) ret[i] = max;
    build(root,ret,0);
    return ret;
}