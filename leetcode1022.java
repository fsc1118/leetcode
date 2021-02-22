package leetcode;

class leetcode1022 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    int result = 0;
    private int toNum(String string){
        int a = 0;
        int length = string.length();
        int b = length;
        //System.out.println(length);
        //int b = Integer.parseInt(string);
        int base = 0;
        while (base < b)
            a = (int) (a + (string.charAt(--length) - '0') * Math.pow(2, base++));
        //    System.out.println(a);
        return a;
    }
    private void dfs(TreeNode root, StringBuilder sb){
        if (root.left == null && root.right == null){
            sb.append(root.val);
            result += toNum(sb.toString());
            sb.deleteCharAt(sb.length() - 1);
            // System.out.println(toNum(sb.toString()));
            return;
        }
        sb.append(root.val);
        if (root.left != null)
            dfs(root.left, sb);
        if (root.right != null)
            dfs(root.right, sb);
        sb.deleteCharAt(sb.length() - 1);
    }
    public int sumRootToLeaf(TreeNode root) {
        dfs(root, new StringBuilder());
        return result;
    }
    
}