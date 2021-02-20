struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
    int result = 0;
    void mid_iterate(TreeNode* root, int low, int high){
        if (root == 0)
            return;
        mid_iterate(root->left, low, high);
        if (root->val >= low && root->val <= high){
            result = result + root->val;
            
        } mid_iterate(root->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        mid_iterate(root, low, high);
        return result;
    }
};