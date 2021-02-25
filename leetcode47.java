package leetcode;

import java.util.*;
class Solution {
    private List<List<Integer>> a = new LinkedList<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        //List<Integer> list = new LinkedList<>();
        Arrays.sort(nums);
        int length = nums.length;
        dfs(nums, length, length, new LinkedList<>(), 0);
        return a;
    }
    private void dfs(int[] nums, int sizeOfArray, int targetLength, List<Integer> currentList, int currentSize) {
        if (targetLength == currentSize){
            a.add(new LinkedList<>(currentList));
            return;
        }
        for (int i = 0; i < sizeOfArray; i++){
            if (nums[i] == 100)
                continue; // empty space
            if (i != 0 && nums[i] == nums[i - 1])
                continue; // repeat element
            currentList.add(nums[i]);
            int temp = nums[i];
            nums[i] = 100;
            dfs(nums, sizeOfArray, targetLength, currentList, currentSize + 1);
            nums[i] = temp;
            currentList.remove(currentSize);
        }
    }
}