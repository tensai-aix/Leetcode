#include "define.h"

void search(struct TreeNode* node,int* cur,int k,int* ret,bool isFind){
    if(isFind) return;
    if(node->left) search(node->left,cur,k,ret,isFind);
    (*cur) ++;
    if((*cur) == k){
        (*ret) = node->val;
        isFind = true;
        return;
    }
    if(node->right) search(node->right,cur,k,ret,isFind);
}
int kthSmallest(struct TreeNode* root, int k) {
    int ret;
    int cur = 0;
    search(root,&cur,k,&ret,false);
    return ret;
}