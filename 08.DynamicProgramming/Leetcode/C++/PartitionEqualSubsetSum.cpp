#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    

using namespace std;



bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    if (sum == 0) return false;
    
    int goal_sum = sum / 2;
    
    sort(nums.begin(), nums.end());
    vector<vector<int> > memo(nums.size() + 1, vector<int>(goal_sum + 1, false));
    memo[0][0] = true;
    
    for (int i = 1; i <= nums.size(); ++i) {
        memo[i][0] = true;
        for (int j = 1; j <= goal_sum; ++j) {
            if (j >= nums[i]) {
                memo[i][j] = memo[i - 1][j - nums[i]];
            }
            
            memo[i][j] |= memo[i - 1][j];
        }
    }
    
    return memo[nums.size()][goal_sum];
}
