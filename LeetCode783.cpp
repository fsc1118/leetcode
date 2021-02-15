#include<algorithm>
#include<limits.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int currentNumber = INT_MIN;
    int difference = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return difference;
    }
    void dfs(TreeNode* root){
        if (root == 0)
            return;
        dfs(root->left);
        difference = min(difference, abs(currentNumber - root->val));
        currentNumber = root->val;
        dfs(root->right);
    }
};