#include "define.h"

#define min -1010
int calMaxLength(struct TreeNode* node,int* ret){
    int left_max = (node->left) ? calMaxLength(node->left,ret) : 0;
    int right_max = (node->right) ? calMaxLength(node->right,ret) : 0;
    int cur = node->val + fmax(left_max,0) + fmax(right_max,0);
    if(cur > (*ret)) (*ret) = cur;
    int to_return = fmax(0,left_max);
    to_return = fmax(to_return,right_max);
    return to_return + node->val;
}
int maxPathSum(struct TreeNode* root) {
    int ret = min;
    calMaxLength(root,&ret);
    return ret;
}