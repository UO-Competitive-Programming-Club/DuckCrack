#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxCoins(vector<int>& nums) {
    int nlen = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int> > memo(nlen + 2, vector<int>(nlen + 2, 0));

    for (int distance = 1; distance <= nlen; distance++) {
        for (int start = 1; start <= nlen - distance + 1; start++) {
            int end = start + distance - 1;
            for (int k = start; k <= end; k++) {
                memo[start][end] = 
                    max(memo[start][end], memo[start][k - 1]+ nums[start - 1] * nums[k] * nums[end + 1]  + memo[k + 1][end] );
            }
        }
    }

    return memo[1][nlen];
}
