struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
    int num = 1;
    int ans = -1;
    void mid_iterate(TreeNode* root, int k){
        if (root == 0)
            return;
        mid_iterate(root->left, k);
        if (num == k){
            ans = root->val;
            num++;
            return;
        } else
            num++;
        mid_iterate(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        mid_iterate(root, k);
        return ans;
    }
};