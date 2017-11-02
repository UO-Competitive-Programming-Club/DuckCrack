class Solution:
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """

        def subsetSum(nums, target):
            dp = [ 1 ] + [ 0 ] * target
            for n in nums:
                for t in range(target, n - 1, -1):
                    dp[t] += dp[t - n]

            return dp[target]
        """
        def subsetSum(nums, target):
            nlen = len(nums)

            dp = [ [ 1 ] + [ 0 for i in range(target) ] for i in range(nlen) ]

            if nums[0] <= target: dp[0][nums[0]] = 1


            for i in range(1, nlen):
                for t in range(target + 1):
                    n = nums[i]
                    dp[i][t] = dp[i - 1][t]
                    if (n <= t): dp[i][t] += dp[i - 1][t - n]

            print(dp)
            return dp[nlen - 1][target]
        """

        all_sum = sum(nums)
        if all_sum < target or (all_sum + target) % 2 == 1:
            return 0
        else:
            return subsetSum(nums, (all_sum + target) // 2)
