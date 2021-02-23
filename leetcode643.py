class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        result = -1.0
        length = len(nums)
        temp = 0
        a = True
        for i in range(0, length - k + 1):
            if (a):

                for j in range(0, k):
                    temp = temp + nums[j]
                result = temp
               # print(result)
                a = False
            else:
                #print(nums[i-1])
                #print(nums[i + k - 1])
                temp = temp - nums[i - 1] + nums[i + k-1]
                result = max(result, temp)
                
                
            
        return result / k