#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numDistinct(string s, string t) {
    int slen = s.size(), tlen = t.size();
    if (tlen > slen) return 0;

    vector<vector<int>> memo(tlen + 1, vector<int>(slen + 1, 0));
    fill(memo.front().begin(), memo.front().end(), 1);

	for (int i = 1; i <= tlen; ++i) {
        for (int j = 1; j <= slen; ++j) {
            if (i > j) continue;

            if (t[i - 1] == s[j - 1]) {
                memo[i][j] = memo[i][j - 1] + memo[i - 1][j - 1];
            } else {
                memo[i][j] = memo[i][j - 1];
            }
        }
    }

    return memo[tlen][slen];
}
