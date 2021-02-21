class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length = len(nums)
        re = length
        i = 0
        while (1):
            if (i >= length):
                break;
            if (nums[i] == val):
                nums.remove(nums[i])
                i = i - 1;
                re = re - 1
            i = i + 1
            length = len(nums)
        return re