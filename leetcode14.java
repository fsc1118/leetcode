package leetcode;

class leetcode14 {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder sBuilder = new StringBuilder();
        if (strs.length == 0)
            return "";
        int length = strs[0].length();
        int i = 0;
        char c = 0;
        while (i < length){     
            for (String s : strs){
                if (c == 0)
                    c = s.charAt(i);
                else if (i >= s.length() || s.charAt(i) != c)
                    return sBuilder.toString();
            }
            sBuilder.append(c);
            i++;
            c = 0;
        }
        return sBuilder.toString();
    }
}