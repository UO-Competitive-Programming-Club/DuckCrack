class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        from collections import defaultdict
        alen = len(A)
        memo = [ defaultdict(int) for i in range(0, alen) ]
        result = 0
        for i in range(0, alen):
            for j in range(0, i):
                diff = A[i] - A[j]
                memo[i][diff] += 1
                if (diff in memo[j]):
                    memo[i][diff] += memo[j][diff]
                    result += memo[j][diff]


        #print(memo)
        return result;
