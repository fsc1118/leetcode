from typing import List

class Solution:
    obstacle: List[List[int]]
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        self.obstacle = obstacleGrid
        depth = len(obstacleGrid)
        width = len(obstacleGrid[0])
        dp = list()
        for i in range(0, depth):
            newList = list()
            dp.append(newList)
            for j in range(0, width):
                newList.append(None)
        return self.recur(dp, 0, 0, width - 1, depth - 1)
    def recur(self, dp: List[List[int]], currentX, currentY, targetX, targetY):
        
        if (currentX > targetX or currentY > targetY):
            return 0
        if (self.obstacle[currentY][currentX] == 1):
            return 0
        if (currentX == targetX and currentY == targetY):
            return 1
        if (dp[currentY][currentX] != None):
            return dp[currentY][currentX]
        i1 = self.recur(dp, currentX + 1, currentY, targetX, targetY)
        i2 = self.recur(dp, currentX, currentY + 1, targetX, targetY)
        dp[currentY][currentX] = i1 + i2
        return i1 + i2