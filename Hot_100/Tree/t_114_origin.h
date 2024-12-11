#include "define.h"

void rebuild(struct TreeNode* node,struct TreeNode** cur){
    struct TreeNode* next = NULL;
    if(node->right) next = node->right;
    node->right = node->left;
    node->left = NULL;
    (*cur) = node;
    if(node->right) rebuild(node->right,cur);    
    (*cur)->right = next;
    if(next) rebuild(node->right,cur); 
}
void flatten(struct TreeNode* root) {
    if(!root) return;
    rebuild(root,&root);
}