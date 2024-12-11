#include "define.h"

bool checkSymmetric(struct TreeNode* left,struct TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    if(checkSymmetric(left->left,right->right) == false) return false;
    if(checkSymmetric(left->right,right->left) == false) return false;
    return true;
}
bool isSymmetric(struct TreeNode* root){
    return checkSymmetric(root,root);
}