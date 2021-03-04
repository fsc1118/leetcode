package leetcode;
import java.util.*;
class leetcode797 {
    private List<List<Integer>> list = new LinkedList<>();
    private void dfs(List<Integer> paths, int[][] garph, int currentLocation, int target){
        if (currentLocation == target){
            list.add(new LinkedList<>(paths));
            return;
        }
        for (int is : garph[currentLocation]) {
            paths.add(is);
            dfs(paths, garph, is, target);
            paths.remove(is);
        }
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        dfs(new LinkedList<>(), graph, 0, graph.length - 1);
        return list;
    }
}