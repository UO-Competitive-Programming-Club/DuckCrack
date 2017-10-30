#include <iostream>
#include <vector>

using namespace std;

/*
 *
 * let dp(s, begin_idx) be the solution for spliting sub-array n[begin_idx::n.length] into s part
 * dp(s, begin_idx) = min(max(subarraySum(begin_idx, k), dp(s - 1, k)))  for (begin_idex < k <= length - s)
 *
 * */

int splitArray(vector<int>& nums, int m) {
    if (nums.empty()) return 0;

    int nlen = nums.size();

    vector<int> subsum(nlen + 1, 0);
    vector<vector<int>> memo(m, vector<int>(nlen, 0));

    /* compute the subsum array */
    for (int i = 1; i <= nlen; ++i) {
        subsum[i] = subsum[i - 1] + nums[i - 1];
    }

    /* when m is zero the result is the sum of entire subarray*/
    for (int i = 0; i < nlen; ++i) {
        memo[0][i] = subsum[nlen] - subsum[i];
        //cout << memo[0][i] << endl;
    }
    
    for (int split_left = 1; split_left < m; ++split_left) {
        for (int begin = 0; begin < nlen - (split_left); ++begin) {
            memo[split_left][begin] = INT_MAX;
            for (int k = begin + 1; k < nlen - (split_left - 1); ++k) {
                memo[split_left][begin] = min(memo[split_left][begin],
                                              max(subsum[k] - subsum[begin], memo[split_left - 1][k]));                       
            }
        }
    }
    

    return memo[m - 1][0];
}
