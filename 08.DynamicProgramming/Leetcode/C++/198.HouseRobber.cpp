#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nlen = nums.size();
        if (nlen == 0) return 0;
        if (nlen == 1) return nums.front();
        if (nlen == 2) return max(nums.front(), nums.back());

        vector<int> memo(nlen, 0);
        memo[0] = nums.front();
        memo[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nlen; i++) {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        }

        return memo.back();
    }
};
