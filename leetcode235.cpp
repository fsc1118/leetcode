#include<algorithm>
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
private:
    TreeNode* node;
    int maxDepth = -1;
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = max(p->val, q->val);
        int b = min(p->val, q->val);
        dfs(root, b, a);
        return node;
    }
    void dfs(TreeNode* root, int firstValue, int secondValue){
        if (root == 0)
            return;
        int val = root->val;
        if (val >= firstValue && val <= secondValue) {
            node = root;
            return;
        }
        if (val > secondValue)
            dfs(root->left, firstValue, secondValue);
        else
            dfs(root->right, firstValue, secondValue);
       
    }
};