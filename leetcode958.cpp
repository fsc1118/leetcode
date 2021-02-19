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
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;   
        q.push(root);
        while (!q.empty()){
            auto node = q.front();
            q.pop();
            if (node == 0){
                 while (!q.empty()){
                    auto node = q.front();
                    if (node != 0)
                        return false;
                    q.pop();
                 }
                 return true;
            } else{
                q.push(node->left);
                q.push(node->right);
            }
            return true;
        }
        
    }
};