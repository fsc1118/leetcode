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
    private:
        queue<int> firstTreeNodes;
        void iterate(TreeNode* firstTree){
            if (firstTree == 0)
                return;
            if (firstTree->left == 0 && firstTree->right == 0){
                firstTreeNodes.push(firstTree->val);
                //cout<<firstTree->val;
                return;
            }
            iterate(firstTree->left);
            iterate(firstTree->right);
        }
        bool checkSecondTree(TreeNode* firstTree){
             if (firstTree == 0)
                return true;
            if (firstTree->left == 0 && firstTree->right == 0){
                int i = firstTreeNodes.front();
                //cout<<i<<endl;
                firstTreeNodes.pop();
                if (firstTree->val != i)
                    return false;
                return true;
            }
            return checkSecondTree(firstTree->left) && checkSecondTree(firstTree->right);
            
        }
    public:
        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            iterate(root1);
            bool a =  checkSecondTree(root2);
            bool b = firstTreeNodes.empty();
            return a && b;
        }
        
        
};