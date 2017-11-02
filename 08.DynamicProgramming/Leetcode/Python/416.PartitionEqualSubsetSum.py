

class Solution:
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """

        def subsetSum(nums, target):
            nlen = len(nums)
            memo = [ [ 0 ] * (target + 1)] * nlen

            for i in range(nlen): memo[i][0] = 1

            for i in range(nlen):
                for t in range(target):
                    if (t > nums[i]):
                        memo[i][t] = (memo[i - 1][t] + memo[i - 1][ t - nums[i]]





        double_positive_sum = (sum(nums) + target);
        return subsetSum(nums, double_positive_sum / 2) if double_positive_sum & 0 else 0
