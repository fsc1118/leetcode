package leetcode;
class leetcode566 {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums[0].length * nums.length != r * c)
            return nums;
        int result[][] = new int[r][c];
        int x_pointer = 0;
        int y_pointer = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++){
                result[i][j] = nums[y_pointer][x_pointer];
                if (x_pointer != nums[0].length - 1)
                    x_pointer++;
                else {
                    x_pointer = 0;
                    y_pointer++;
                }
            }
        }
        return result;
    }
}