
package leetcode;

import java.util.*;

class leetcode93 {
    List<String> b = new LinkedList<>();
    private void dfs(String original_string, int length, List<String> list, int currentIndex, int num){
        //System.out.println("s");
        if (num > 4)
            return;
        if (num == 4 && currentIndex == length){
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 3; i++){
                sb.append(list.get(i));
                //System.out.println(list.get(i));
                sb.append(".");
            }
            //System.out.println(list.get(3));
            sb.append(list.get(3));
            b.add(sb.toString());
            return;
        }
        if (currentIndex == length)
            return;
        String str1 = original_string.substring(currentIndex, currentIndex + 1);
        list.add(str1);
        dfs(original_string, length, list, currentIndex + 1, num + 1);
        list.remove(list.size() - 1);
        if (original_string.charAt(currentIndex) == '0')
            return;
        if (currentIndex == length - 1)
            return;
        String str2 = original_string.substring(currentIndex, currentIndex + 2);
        list.add(str2);
        dfs(original_string, length, list, currentIndex + 2, num + 1);
        list.remove(list.size() - 1);
        if (currentIndex == length - 2)
            return;
        String str3 = original_string.substring(currentIndex, currentIndex + 3);
        if (Integer.parseInt(str3) > 255)
            return;
        list.add(str3);
        dfs(original_string, length, list, currentIndex + 3, num + 1);
        list.remove(list.size() - 1);      
    }
    public List<String> restoreIpAddresses(String s) {
        int length = s.length();
        if (length < 4 || length > 12)
            return b;
        dfs(s, length, new LinkedList<>(), 0, 0);
        return b;
    }
}