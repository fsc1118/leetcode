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
#include<queue>
using namespace std;

class Solution {   
    private:
        long result = LONG_MAX;
        bool a = false;
        void dfs(TreeNode* root, int minimum){
            if (root == 0)
                return;
            if (root->val > result)
                return;
            if (root->val > minimum && root->val < result){
                a = true;
                result = root->val;
            }
            dfs(root->left, minimum);
            dfs(root->right, minimum);
        }
    public:
        int findSecondMinimumValue(TreeNode* root) {
            dfs(root, root->val);
            if (a)
                return (int)result;
            return -1;
        }

};