import sys
class Solution:
    def minPathSum(self, grid: List[List[int]]):
        depth = len(grid)
        width = len(grid[0])
        dp = list()
        for i in range(0, depth):
            newList = list()
            dp.append(newList)
            for j in range(0, width):
                newList.append(None)
        return self.recur(dp, grid, 0, 0, width - 1, depth - 1)

    def recur(self, dp: List[List[int]], grid: List[List[int]], currentX:int, currentY:int, targetX:int, targetY:int):
        if (currentX > targetX or currentY > targetY):
            return sys.maxsize
        if (currentX == targetX and currentY == targetY):
            return grid[currentY][currentX]
        if (dp[currentY][currentX] != None):
            return dp[currentY][currentX]
        i1 = self.recur(dp, grid, currentX + 1, currentY, targetX, targetY)
        i2 = self.recur(dp, grid, currentX, currentY + 1, targetX, targetY)
        minimum = min([i1, i2]) + grid[currentY][currentX]
        dp[currentY][currentX] = minimum 
        return minimum