class Solution:
    def climbStairs(self, n: int) -> int:
        a = dict()
        return self.dfs(n, 0, a)
    def dfs(self, target:int, currentHeight:int, d:dict):
        if (currentHeight > target):
            return 0;
        if (currentHeight == target):
            return 1;
        if (d.__contains__(currentHeight)):
            return d[currentHeight];
        choice = self.dfs(target, currentHeight + 1, d)+self.dfs(target, currentHeight + 2, d)
        d[currentHeight] = choice
        return choice