/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int result = 0;
    public int sumNumbers(TreeNode root) {
        dfs(root, new StringBuffer());
        return result;
    }
    private void dfs(TreeNode root, StringBuffer sb){
        if (root == null)
            return;
        if (root.left == null && root.right == null){
            sb.append(String.valueOf(root.val));
            if (sb.length() == 0)
                return;
           // System.out.println(Integer.parseInt(sb.toString()));
            result = result + Integer.parseInt(sb.toString());
            sb.deleteCharAt(sb.length() - 1);
            return;
        }

        sb.append(String.valueOf(root.val));
        dfs(root.left, sb);
        dfs(root.right, sb);
        sb.deleteCharAt(sb.length() - 1);
    }
}