package leetcode;


class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    private int max = -1;
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null)
            return 0;
        dfs(root);
        return max;
    }
    private void dfs(TreeNode root){
        if (root == null)
            return;
        max = Math.max(findLength(root.left) + findLength(root.right),max);
        dfs(root.left);
        dfs(root.right);
    }
    private int findLength(TreeNode root){
        if (root == null)
            return 0;
        return Math.max(findLength(root.left),findLength(root.right))+1;
    }
}