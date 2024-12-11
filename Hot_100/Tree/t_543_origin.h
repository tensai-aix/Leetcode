#include "define.h"

int calMaxLength(struct TreeNode* node,int* ret){
    if(!node) return 0;
    int left_max = calMaxLength(node->left,ret);
    int right_max = calMaxLength(node->right,ret);
    int cur = left_max + right_max;
    if(cur > (*ret)) (*ret) = cur;
    return fmax(left_max,right_max) + 1;
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int ret = 0;
    calMaxLength(root,&ret);
    return ret;
}