import sys
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        depth = len(triangle)
        width = 1
        dp = list()
        for i in range(0, depth):
            newList = list()
            dp.append(newList)
            for j in range(0, width):
                newList.append(None)
            width = width + 1
        return self.recur(triangle, dp, 0, 0, depth - 1)

    def recur(self, triangle: List[List[int]], dp: List[List[int]], currentx: int, currenty: int, targety: int):
        if (currentx < 0 or currentx > currenty):
            return sys.maxsize
        if (currenty == targety):
            return triangle[currenty][currentx]
        if (dp[currenty][currentx] != None):
            return dp[currenty][currentx]
        i1 = self.recur(triangle, dp, currentx + 1, currenty + 1, targety)
        i2 = self.recur(triangle, dp, currentx, currenty, targety)
        minimum = min([i1, i2]) + triangle[currenty][currentx]
        dp[currenty][currentx] = minimum
        return minimum
