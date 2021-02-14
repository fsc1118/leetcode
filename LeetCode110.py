# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isBalanced(self, root: TreeNode):
        if (root is None):
            return True
        a = self.height(root.left)
        b = self.height(root.right)
        if (abs(a-b) > 1):
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
    def height(self, root:TreeNode):
        if (root is None):
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1
