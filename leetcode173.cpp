#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class BSTIterator {
    queue<int> q;
    void iterate(TreeNode* root){
        if (root == 0)
            return;
        iterate(root->left);
        q.push(root->val);
        iterate(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        iterate(root);
    }
    
    int next() {
        int i = q.front();
        q.pop();
        return i;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */