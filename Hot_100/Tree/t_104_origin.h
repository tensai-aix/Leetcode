#include "define.h"

void findMax(struct TreeNode* node,int* ret,int cur){
    if(!node) return;
    cur++;
    if(cur > (*ret)) (*ret) = cur;
    if(node->left) findMax(node->left,ret,cur);
    if(node->right) findMax(node->right,ret,cur);
}
int maxDepth(struct TreeNode* root) {
    int ret = 0;
    findMax(root,&ret,0);
    return ret;
}