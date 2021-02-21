package leetcode;

class leetcode125 {
    public boolean isPalindrome(String s) {
        int front = 0;
        int back = s.length() - 1;
        while (front < back){
            char a = s.charAt(front);
            if (!Character.isAlphabetic(a) && !Character.isDigit(a)){
                front++;
                continue;
            }
            char b = s.charAt(back);
            if (!Character.isAlphabetic(b) && !Character.isDigit(b)){
                back--;
                continue;
            }
            if (!camparedIgnoredCase(a, b))
                return false;           
        }
        return true;
    }
    private boolean camparedIgnoredCase(char a, char b){
        if (a == b)
            return true;
        if (Character.isUpperCase(a))
            return b == a + 32;
        if (Character.isLowerCase(a))
            return a == b + 32;
        return false;

        
    }
}