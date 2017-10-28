#include <iostream>
#include <vector>

using namespace std;

bool isInterleave(string sa, string sb, string tstr) {
    int alen = sa.length(), blen = sb.length(), tlen = tstr.length();
    if (alen + blen != tlen) return false;

    vector<vector<bool>> memo(alen + 1, vector<bool> (blen + 1, false));
    memo[0][0] = true;

    for (int i = 1; i <= blen; ++i) {
        memo[0][i] = memo[0][i - 1] && (sb[i - 1] == tstr[i - 1]);
    }
    
    for (int j = 1; j <= alen; ++j) {
        memo[j][0] = memo[j - 1][0] && (sa[j - 1] == tstr[j - 1]);
    }        

    for (int i = 1; i <= alen; ++i) {
        for (int j = 1; j <= blen; ++j) {
            int sa_end = sa[i - 1], sb_end = sb[j - 1], st_end = tstr[i + j - 1];

            if (sa_end == st_end) {
                memo[i][j] = memo[i][j] || memo[i - 1][j];
            }

            if (sb_end == st_end) {
                memo[i][j] = memo[i][j] || memo[i][j - 1];
            }                
        }
    }

    return memo[alen][blen];
}
