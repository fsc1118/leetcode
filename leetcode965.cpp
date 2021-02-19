struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    bool check(TreeNode* root, int target){
        if (root == 0)
            return true;
        if (root->val != target)
            return false;
        return check(root->left, target) && check(root->right, target);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return check(root, root->val);
    }
};