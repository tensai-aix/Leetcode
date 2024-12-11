#include "define.h"

struct TreeNode* BuildTree(int* nums,int begin,int end){
    if(begin > end) return NULL;
    struct TreeNode* new_treenode = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    int mid = (begin + end) / 2;
    new_treenode->val = nums[mid];
    new_treenode->left = BuildTree(nums,begin,mid-1);
    new_treenode->right = BuildTree(nums,mid+1,end);
    return new_treenode;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return BuildTree(nums,0,numsSize-1);
}