#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinCoin(int n, vector<int>& coins) {
    int clen = coins.size();
    vector<int> memo(clen + 1, INT_MAX);

    memo[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int coin: coins) {
            if (i > coin) {
                int previous_min = memo[i - coin];
                if (previous_min == INT_MAX) continue;
                memo[i] = min(memo[i], previous_min + 1);
            }
        }
    }

    return memo[clen];
}
