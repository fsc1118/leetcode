#include<algorithm>
using namespace std;
class Solution {
    public:
        int currentMax = -1;
        
        struct TreeNode {
            int val;
            struct TreeNode *left;
            struct TreeNode *right;
        };
        struct TreeNode* tn;
        struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
            dfs(root, p->val, q->val,0);
            return tn;
        }
        void dfs(struct TreeNode* root, int target1, int target2, int depth){
            if (root == 0)
                return;
            if (!isFather(root, target1))
                return;
            if (!isFather(root, target2))
                return;
            if (depth > currentMax){
                tn = root;
                currentMax = depth;
            }
            dfs(root->left, target1, target2, depth + 1);
            dfs(root->right, target1, target2, depth + 1);
        }

        bool isFather(struct TreeNode* root, int target){
            if (root == 0)
                return false;
            if (root->val == target)
                return true;
            return isFather(root->right, target) || isFather(root->left, target);
        }
};