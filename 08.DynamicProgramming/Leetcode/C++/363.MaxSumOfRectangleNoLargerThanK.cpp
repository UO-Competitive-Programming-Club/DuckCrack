#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int largestSubarraySumLessThanK(vector<int>& row, int k) {
    int cur_sum = 0, cur_max = INT_MIN;

    set<int> accuSet;
    accuSet.insert(0);

    for (int n: row) {
        cur_sum += n;
        auto it = accuSet.lower_bound(cur_sum - k);
        if (it != accuSet.end()) {
            cur_max = max(cur_max, cur_sum - *it);
        }
        
        accuSet.insert(cur_sum);
    }

    return cur_max;
}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int h = matrix.size(), w = matrix.front().size();
    int result = INT_MIN;
    for (int base_row = 0; base_row < h; ++base_row) {
        vector<int> memo(w, 0);
        for (int cur_row = base_row; cur_row >= 0; --cur_row) {
            for (int col = 0; col < w; ++col) {
                memo[col] += matrix[cur_row][col];
            }

            result = max(result, largestSubarraySumLessThanK(memo, k));
            if (result == k) { return k; }
        }
    }

    return result;
}  

