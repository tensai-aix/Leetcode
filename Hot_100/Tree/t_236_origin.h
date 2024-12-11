#include "define.h"

void findMax(struct TreeNode* node,int* ret,int level){
    if((!node->left) && (!node->right) && (level > (*ret))) (*ret) = level;
    if(node->left) findMax(node->left,ret,level + 1);
    if(node->right) findMax(node->right,ret,level + 1);
}
bool findLength(struct TreeNode* root,struct TreeNode* find,int* ret,int level){
    if(root == find){
        (*ret) = level;
        return true;
    }
    if(root->left && findLength(root->left,find,ret,level + 1) == true) return true;
    if(root->right && findLength(root->right,find,ret,level + 1) == true) return true;
    return false;
}
bool buildWay(struct TreeNode* root,struct TreeNode* find,int* ret,int level){
    if(root == find) return true;
    if(root->left && buildWay(root->left,find,ret,level + 1) == true){
        ret[level] = 1;
        return true;
    }
    if(root->right && buildWay(root->right,find,ret,level + 1) == true){
        ret[level] = 2;
        return true;
    } 
    return false;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int length = 0;
    int length_p = 0;
    int length_q = 0;
    findMax(root,&length,0);
    findLength(root,p,&length_p,0);
    findLength(root,q,&length_q,0);
    int* way_p = (int*) malloc (length * sizeof(int));
    int* way_q = (int*) malloc (length * sizeof(int)); 
    buildWay(root,p,way_p,0);
    buildWay(root,q,way_q,0);
    struct TreeNode* ret = root;
    for(int i = 0;i < fmin(length_p,length_q);i++){
        if(way_p[i] != way_q[i]) break;
        if(way_p[i] == 1) ret = ret->left;
        else ret = ret->right;
    }
    return ret;
}