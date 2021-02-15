#include<vector>
using namespace std;
class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};
class Solution {
    private:
        int size = 0;
        vector<vector<int>> returnedVector;
    public:
        vector<vector<int>> levelOrder(Node* root) {
            dfs(root, 0);
            return returnedVector;
        }
        void dfs(Node* root, int depth){
            if (root == 0)
                return;
            if (depth == size){
                vector<int> newVector;
                newVector.push_back(root->val);
                size++;
                returnedVector.push_back(newVector);
            } else {
                returnedVector.at(depth).push_back(root->val);
            }
            for (Node* node : root->children)
                dfs(node, depth + 1);
        }

};