#include "define.h"

void findMax(struct TreeNode* node,int* ret,int level){
    if((!node->left) && (!node->right) && (level > (*ret))) (*ret) = level;
    if(node->left) findMax(node->left,ret,level + 1);
    if(node->right) findMax(node->right,ret,level + 1);
}
void Search(struct TreeNode* node,int level,long* search,int* ret){
    for(int i = 0;i <= level;i++){
        if(node->val == search[i]) (*ret)++;
        search[i] -= node->val;
    }
    if(node->left) Search(node->left,level + 1,search,ret);
    if(node->right) Search(node->right,level + 1,search,ret);
    for(int i = 0;i <= level;i++) search[i] += node->val;
}
int pathSum(struct TreeNode* root, int targetSum) {
    if(!root) return 0;
    int length = 0;
    findMax(root,&length,1);
    long* search = (long*) malloc (length * sizeof(long));
    for(int i = 0;i < length;i++) search[i] = targetSum;
    int ret = 0;
    Search(root,0,search,&ret);
    return ret;
}