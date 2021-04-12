class Solution:
    def is_odd(self, integer:int):
        return integer % 2
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        length = len(arr)
        for i in range(0, length - 2):
            if (self.is_odd(arr[i]) and self.is_odd(arr[i + 1]) and self.is_odd(arr[i + 2])):
                return True
        return False
