#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LongestCommonSubstr(string& A, string& B) {
    int alen = A.size(), blen = B.size();
    int result = 0;
    vector<vector<int> >memo(alen + 1, vector<int>(blen + 1, 0));

    for (int i = 1; i < alen; i++) {
        for (int j = 1; j < blen; j++) {
            if (A[i] == B[j]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = 0;
            }

            result = max(result, memo[i][j]);
        }
    }

    return result;
}
