/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include<stdbool.h>


static bool whether_exist(struct TreeNode* root, int target, struct TreeNode* from){
    if (root == 0)
        return false;
    if (root->val == target && root != from)
        return true;
    return (root->val > target) ? whether_exist(root->left, target, from) : whether_exist(root->right, target, from);
}
static bool mid_iterate(struct TreeNode* root, struct TreeNode* current_node, int k){
    //printf("A\n");
    if (current_node == 0)
        return false;
    return whether_exist(root, k - current_node->val, current_node) || mid_iterate(root, current_node->left, k) || mid_iterate(root, current_node->right, k);
}
bool findTarget(struct TreeNode* root, int k){
    return mid_iterate(root, root, k);
}