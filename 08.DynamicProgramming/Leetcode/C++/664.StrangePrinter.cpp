#include <iostream>
#include <vector>

using namespace std;

int turn(vector<vector<int>>& memo, const string& s, int i, int j) {
    if (i > j) return 0;

    // if the sub problem has been calculated
    if (memo[i][j] != 0) return memo[i][j];
    
    // this is the worest case, print one character each time
    int result = turn(memo, s, i, j - 1) + 1;

    for (int k = i; k < j; ++k) {
        if (s[k] == s[j]) {
            result = min(result, (turn(memo, s, i, k) + turn(memo, s, k + 1, j - 1)));
        }
    }

    memo[i][j] = result;
    return result;
}

int strangePrinter(string s) {
    int slen = s.length();
    vector<vector<int>> memo(slen, vector<int>(slen, 0));
    return turn(memo, s, 0, slen - 1);
}

