struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isLeaves(TreeNode* root){
        return root->left == 0 && root->right == 0;
    }
    void iterate(TreeNode* root, int target){
        if (root == 0)
            return;
        iterate(root->left, target);
        iterate(root->right, target);
        if (root->left != 0){
            if (isLeaves(root->left) && root->left->val == target)
                root->left = 0;
        }
        if (root->right != 0){
            if (isLeaves(root->right) && root->right->val == target)
                root->right = 0;
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        iterate(root, target);
        if (isLeaves(root) && root->val == target)
            root = 0;
        return root;
    }
    
};