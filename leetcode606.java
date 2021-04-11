package leetcode;

class leetcode606 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
    public String tree2str(TreeNode t) {
        if (t == null){
            return new String();
        }
        StringBuilder sb = new StringBuilder();
        preTransversal(sb, t);
        return sb.toString();
    }
    private void preTransversal(StringBuilder sb, TreeNode tNode) {
        sb.append(String.valueOf(tNode.val));
        if (tNode.left == null && tNode.right == null){
            return;
        }
        
        if (tNode.left != null){
            sb.append("(");
            preTransversal(sb, tNode.left);
            sb.append(")");
        } else{
            sb.append("()");
        }
        if (tNode.right != null){
            sb.append("(");
            preTransversal(sb, tNode.right);
            sb.append(")");
        }
    }
}