#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int> memo { 0 };

        for (int i = 1; i <= n; i++) {
            memo.push_back(INT_MAX);
            for (int j = 1; j *j  <= i; j++) {
                memo[i] = min(memo[i - j * j] + 1, memo[i]);
            }
        }

        return memo[n];
    }
};
