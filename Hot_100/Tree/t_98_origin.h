#include "define.h"

bool check(struct TreeNode* node,int maxval,int minval,bool isMin,bool isMax){
    if(node->left && ((node->left->val >= node->val) || (node->left->val <= minval && isMin) || check(node->left,node->val,minval,isMin,true) == false)) return false;
    if(node->right && ((node->right->val <= node->val) || (node->right->val >= maxval && isMax) || check(node->right,maxval,node->val,true,isMax) == false)) return false;
    return true;
}
bool isValidBST(struct TreeNode* root) {
    return check(root,0,0,false,false);
}