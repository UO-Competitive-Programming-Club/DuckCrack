#include <iostream>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
    int slen = s.size();
    vector<vector<int>> memo(slen, vector<int>(slen, 0));

    for (int l = 1; l <= slen; ++l) {
        for (int begin = 0; begin < slen - l + 1; ++begin) {

            int end = begin + l - 1, 
                substring_length = end - begin + 1;

            // the case where the outer most parens will make the 
            // whole string a valid substring
            if ((s[begin] == '(' && s[end] == ')') && 
                (memo[begin - 1][end - 1] == substring_length)) {

                memo[begin][end] = substring_length;
                continue;
            }         

            for (int k = begin + 1; k < end; ++k) {
                // the case where the substring is consist of two valid substrings
                if (memo[begin][k] + memo[k + 1][end] == substring_length) {
                    memo[begin][end] = substring_length;
                } else {
                    memo[begin][end] = max(memo[begin][end], max(memo[begin][k], memo[k + 1][end]));
                }
            }
        }
    }


    return memo[0][slen - 1];
}



