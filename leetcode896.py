class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        length = len(A)
        if (length == 0):
            return True
        a = A[0] > A[length - 1]
        if (not a):
            for i in range(1, length):
                if (A[i] < A[i - 1]):
                    return False
        else:
            for i in range(1, length):
                if (A[i] > A[i - 1]):
                    return False
        return True