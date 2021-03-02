typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
}TreeNode;

class Solution {
    TreeNode* iterate(TreeNode* root, int key){
        if (root->val > key){
            if (root->left == 0)
                return 0;
            if (root->left->val == key)
                return root;
            return iterate(root->left, key);
        } else if (root->val < key){
            if (root->right == 0)
                return 0;
            if (root->right->val == key)
                return root;
            return iterate(root->right, key);
        }
        return 0;
    }
    TreeNode* leftEnd(TreeNode* root){
        if (root->left == 0)
            return root;
        return leftEnd(root->left);
    }
    TreeNode* rightEnd(TreeNode* root){
        if (root->right == 0)
            return root;
        return leftEnd(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        /*special case*/
        if (root == 0)
            return root;
        if (root->val == key){ //remove the root
            TreeNode* leftmost_leaf_on_right = 0;
            if (root->right == 0){
                return root->left;
            }
            leftmost_leaf_on_right = leftEnd(root->right);
            TreeNode* left = root->left;
            leftmost_leaf_on_right->left = left;
            return root->right;
        }
        TreeNode* parent = iterate(root, key);
        if (parent == 0)
            return root;
        //cout<<parent->val<<endl;
        bool leftOrRight;
        TreeNode* target = 0;
        if (parent->right != 0 && parent->right->val == key){
            leftOrRight = false;
            target = parent->right;
        }
        else{
            leftOrRight = true;
            target = parent->left;
        }
        if (leftOrRight) {
            if (target->right == 0){
                parent->left = target->left;
            } else{
                TreeNode* leftTree = target->left;
                TreeNode* dest = leftEnd(target->right);
                dest->left = leftTree;
                parent->left = target->right;
            }
        } else {
            //cout<<target->val<<endl;
            if (target->left == 0){
                parent->right = target->right;
            } else{
                TreeNode* leftTree = target->left;\
                if (target->right == 0){
                    parent->right = leftTree;
                } else{
                    TreeNode* dest = leftEnd(target->right);
                    dest->left = leftTree;
                    parent->right = target->right;
                }
                
            }

        }
        return root;
    }
    
};