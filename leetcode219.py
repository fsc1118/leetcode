class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        length = len(nums)
        map = dict()
        for i in range(0, length):            
            if (map.__contains__(nums[i])):
               # print(i)               
                index = map[nums[i]]
                #print(index)
                if (i - index  <= k):
                    return True
            map[nums[i]] = i;
        return False