#include<stack>
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
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty()){
            Node* node = s.top();
            if (node == 0)
                break;
            s.pop();
            result.push_back(node->val);
            int size = node->children.size();
            for (int i = size - 1; i >= 0; i--){
                if (node->children.at(i) != 0)
                    s.push(node->children.at(i));
            }
        }
        return result;
    }
};
