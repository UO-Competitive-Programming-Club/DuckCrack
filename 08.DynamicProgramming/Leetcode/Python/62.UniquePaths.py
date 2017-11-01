class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        w, h = n, m
        memo = [ [1] * w ] * h
        for r in range(1, h):
            for c in range(1, w):
                memo[r][c] =  memo[r - 1][c] +  memo[r][c - 1]

        return memo[h - 1][w - 1]
