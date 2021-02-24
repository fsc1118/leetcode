class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        a = list()
        width = len(matrix[0])
        depth = len(matrix)
        for i in range(0, width):
            b = list()
            for j in range(0, depth):
                b.append(matrix[j][i])
            a.append(b)
        return a