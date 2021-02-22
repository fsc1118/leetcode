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
    TreeNode* parentOfx = 0;
    TreeNode* parentOfy = 0;
    bool result;
    int depthX;
    int depthY;
    void dfs(TreeNode* root, int x, int y, int depth, TreeNode* father){
        if (root == 0)
            return;
        if (root -> val == x){
            depthX = depth;
            parentOfx = father;
            if (parentOfy != 0)
                result = (parentOfy != father && depthX == depthY);
                return;
        }
        if (root -> val == y){
            parentOfy = father;
            depthY = depth;
            if (parentOfx != 0)
                result = (parentOfx != father && depthY == depthX);
                return;
        }
        dfs(root->left, x, y, depth + 1, root);
        dfs(root->right, x, y, depth + 1, root);

    }
        

public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, 0);
        return result;
    }
};