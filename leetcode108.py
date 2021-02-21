
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.recur(nums,0, len(nums) - 1,len(nums))
    def recur(self, list: List[int], start:int, end:int, length:int) -> TreeNode:
        if (start < 0 or end >= length or start > end):
            return
        mid = (int)((start + end) / 2)
        #print(mid)
        tn = TreeNode(list[mid])
        tn.left = self.recur(list, start, mid - 1, length)
        tn.right = self.recur(list, mid + 1, end, length)
        return tn