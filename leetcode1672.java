package leetcode;

import java.util.Arrays;

class leetcode1672 {
    public int maximumWealth(int[][] accounts) {
        int max = -1;
        int length = accounts.length;
        for (int i = 0; i < length; i++) {
            max = Math.max(Arrays.stream(accounts[i]).sum(), max) ; 
        }
        return max;
    }
}