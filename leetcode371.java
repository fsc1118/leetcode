package leetcode;

class leetcode371 {
    public int getSum(int a, int b) {
        int carry = 0;
        int result = 0x0000;
        int mask = 0x0001;
        for (int i = 0;  i<=31; i++){
            int first = (a>>>i) & mask;
            int second = (b>>>i) & mask;
            int another_carry = 0;
            int num = first ^ second;
            if (first == 1 && second == 1)
                another_carry = 1;
            int f = 0;
            if (carry == 1){
                if (num == 1){
                    f = 0;
                    carry = 1;
                } else if (another_carry == 1){
                    f = 1;
                    carry = 1;
                } else{
                    f = 1;
                    carry = 0;
                }
            } else{
                if (num == 1){
                    f = 1;
                } else if (another_carry == 1){
                    carry = 1;
                    f = 0;
                } else{
                    f = 0;
                }
            }
            result = result ^ (f<<i);
        }
        return result;
    }
}