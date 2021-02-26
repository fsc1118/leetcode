package leetcode;

import java.util.*;
class leetcode117 {
    class Node {
        int val;
        Node left;
        Node right;
        Node next;
    }
    List<Queue<Node>> a = new LinkedList<>();
    public Node connect(Node root) {
        dfs(root, 0);
        while (!a.isEmpty()){
            Queue<Node> get = a.remove(0);
            Node node1 = get.poll();
            Node pointer1 = node1; 
            while(!get.isEmpty()){
                Node node2 = get.poll();
                pointer1.next = node2;
                pointer1 = node2;
            }
            
        }
        return root;
    }
    private void dfs(Node root, int depth){
        if (root == null)
            return;
        if (a.size() <= depth){
            Queue<Node> list = new LinkedList<>();
            list.add(root);
            a.add(list);
        } else {
            a.get(depth).add(root);
        }
        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
 }