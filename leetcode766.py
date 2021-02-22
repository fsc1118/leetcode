class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        width = len(matrix[0])
        depth = len(matrix)
        for i in range(0, width):
            if (not self.__diagonalCheck(matrix, i, 0, depth, width, matrix[0][i])):
                return False
        for i in range(1, depth):
            if (not self.__diagonalCheck(matrix, 0, i, depth, width, matrix[i][0])):
                return False
        return True
    def __diagonalCheck(self, matrix: List[List[int]], startIndexX:int, startIndexY:int, depth:int, width:int, target:int) -> bool:
        currentIndexX = startIndexX
        currentIndexY = startIndexY
        while (currentIndexX < width and currentIndexY < depth):
            if (matrix[currentIndexY][currentIndexX] != target):
                return False
            currentIndexX = currentIndexX + 1
            currentIndexY = currentIndexY + 1
        return True


