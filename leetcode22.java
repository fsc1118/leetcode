import java.util.*;
class Solution {
    private List<String> list = new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        dfs(0, 2 * n, 0, "", false,n,0);
        return list;
    }
    private void dfs(int numberOfLeft, int targetLength, int currentLength,String sb, boolean isRight, int maxLeft,int totalLeft){
    
        if (isRight){
            if (numberOfLeft <= 1)
                return;
            if (currentLength==targetLength){
                list.add(sb);
                return;
            }

            dfs(numberOfLeft-1,targetLength,currentLength+1,sb+"(",false,maxLeft,totalLeft);
            dfs(numberOfLeft-1,targetLength,currentLength+1,sb+")",true,maxLeft,totalLeft);
        } else{
            if (totalLeft > maxLeft)
                return;
            if (currentLength==targetLength){
                list.add(sb);
                return;
            }
            dfs(numberOfLeft+1,targetLength,currentLength+1,sb+"(",false,maxLeft,totalLeft+1);
            dfs(numberOfLeft+1,targetLength,currentLength+1,sb+")",true,maxLeft,totalLeft+1);
        }
    }
}