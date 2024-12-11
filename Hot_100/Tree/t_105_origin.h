// 利用先序和中序遍历构造树，方法为找到根节点，然后递归构造左右子树
#include "define.h"

struct TreeNode* buildNode(int val){
    struct TreeNode* new_node = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
struct TreeNode* build(int* preorder,int preBegin,int preEnd,int* inorder,int inBegin,int inEnd){
    if(inBegin > inEnd) return NULL;
    else if(inBegin == inEnd) return buildNode(inorder[inBegin]);
    int i;
    for(i = inBegin;i <= inEnd;i++){
        if(inorder[i] == preorder[preBegin]) break;
    }
    int length = i - inBegin;
    struct TreeNode* root = buildNode(inorder[i]);
    root->left = build(preorder,preBegin + 1,preBegin + length,inorder,inBegin,i - 1);
    root->right = build(preorder,preBegin + length + 1,preEnd,inorder,i + 1,inEnd);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder,0,preorderSize - 1,inorder,0,inorderSize - 1);
}