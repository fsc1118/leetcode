class Solution {
    public int[] twoSum(int[] nums, int target) {
    	/*first one: number*/
    	/*second one: index*/
		Map<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int k = nums[i];
			if (map.containsKey(target - k)) {
				int[] a = {map.get(target - k), i};
				return a;
			} else {
				map.put(k, i);
			}
		}
		return null;
    }
}