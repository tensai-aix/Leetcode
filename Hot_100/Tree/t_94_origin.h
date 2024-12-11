#include "define.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void Mid_Reverse(struct TreeNode* node,int* ret,int* length){
    if(!node) return;
    if(node->left){
        Mid_Reverse(node->left,ret,length);
    }
    ret[*length] = node->val;
    (*length)++;
    if(node->right){
        Mid_Reverse(node->right,ret,length);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int ret[110] = {0};
    (*returnSize) = 0;
    Mid_Reverse(root,ret,returnSize);
    if(!(*returnSize)) return NULL;
    int* to_return = (int*) malloc ((*returnSize) * sizeof(int));
    memcpy(to_return,ret,(*returnSize)*sizeof(int));
    return to_return;
}