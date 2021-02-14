#include<stdlib.h>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
    public:
        vector<vector<int>> a;
        int size = 0;
        vector<vector<int>> levelOrder(TreeNode* root) {
            dfs(root, 0);
            return a;
        }
        void dfs(TreeNode* root, int depth){
            if (root == 0)
                return;
            if (depth == size){
                size++;
                vector<int> newVector;
                newVector.push_back(root->val);
                a.push_back(newVector);
            } else
                a.at(depth).push_back(root->val);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
};