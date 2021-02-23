class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        result = 0
        k = 0
        temp = 0
        t = False
        for i in range(0, length):
            if (height[i] >= k): #find right bounds
                k = height[i]
                g = 0
                for c in range(i + 1, length):
                    g = max(g, height[c])
                    if (height[c] >= k):
                        a = True
                        break
                if (not a):
                    result = result + temp
                    temp = 0
                    k = g
                else:
                    result = result + temp
                    temp = 0
                   # k = 0               
            else:
                temp = temp + k - height[i]
        return result

        
