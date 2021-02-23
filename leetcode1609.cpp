#include<vector>
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
   bool a = true;
    vector<int> vec;
    int size = 0;
    void dfs(TreeNode* root, int currentDepth){
        if (root == 0)
            return;
        if (currentDepth % 2 == 0){
            if (root->val % 2 != 1){
                a = false;
                return;
            }
        } else{
            if (root->val % 2 != 0){
                a = false;
                return;
            }
        }
        if (currentDepth == size){
            vec.push_back(root->val);
            size++;
        } else{
            int k = vec.at(currentDepth);
            if (currentDepth % 2 == 0){
                if (root-> val > k)
                    vec[currentDepth] = root->val;
                else{
                    a = false;
                    return;
                }
            } else{
                if (root-> val < k)
                    vec[currentDepth] = root->val;
                else{
                    a = false;
                    return;
                }
            }
        }
        dfs(root->left, currentDepth + 1);
        dfs(root->right, currentDepth + 1);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        dfs(root ,0);
        return a;
        
    }
};