package leetcode;

import java.util.Arrays;

class leetcode67 {
    public String addBinary(String a, String b) {
        int length1 = a.length();
        int length2 = b.length();
        char[] c = new char[Math.abs(length1 - length2)];
        Arrays.fill(c, '0');
        if (length1 > length2){
            b = new String(c) + b;
        } else{
            a = new String(c) + a;
        }
       // System.out.println(a);
        //System.out.println(b);
        
        int minLength = a.length();
        int carry = 0;
        int pointerToFirst = minLength - 1;
        StringBuilder result = new StringBuilder();
        int count = 0;
        while (count < minLength){
            int r1 = a.charAt(pointerToFirst) - '0';
            int r2 = b.charAt(pointerToFirst--) - '0';
            int r3 = r1 + r2 + carry;
            int n = r3 % 2;
            carry = (r3 >= 2) ? 1 : 0;
            StringBuilder sb = new StringBuilder(String.valueOf(n));
            //System.out.println(sb);
            result = sb.append(result);
            count++;
        }
        if (carry == 1)
            result = new StringBuilder("1").append(result);
        return result.toString();
    }
}